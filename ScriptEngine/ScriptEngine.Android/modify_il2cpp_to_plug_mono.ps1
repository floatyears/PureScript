$rootDir = [System.IO.Path]::GetDirectoryName($myInvocation.MyCommand.Definition)
if(Test-Path(Join-Path $rootDir unityLibrary)){
    $sourceCodeDir = Join-Path $rootDir unityLibrary\src\main\Il2CppOutputProject\IL2CPP\
}else {
    $sourceCodeDir = $rootDir
}
Write-Host $sourceCodeDir

$il2cpp_api_type = Join-Path $sourceCodeDir libil2cpp/il2cpp-api-types.h
$content = Get-Content -Path $il2cpp_api_type
$match = $content | Select-String -Pattern 'Il2CppThreadAttachCallback'
# Write-Host $content
if($match.Matches.Count -eq 0)
{
    Add-Content $il2cpp_api_type "typedef void (*Il2CppThreadAttachCallback)(Il2CppThread* thread);"
}

$il2cpp_api_functions = Join-Path $sourceCodeDir libil2cpp/il2cpp-api-functions.h
$content = Get-Content -Path $il2cpp_api_functions
$match = $content | Select-String -Pattern 'il2cpp_set_thread_attach_detach_callback'
# Write-Host $content
if($match.Matches.Count -eq 0)
{
    Set-Content -Path $il2cpp_api_functions $content.Replace('// thread', "// thread`r`nDO_API(void, il2cpp_set_thread_attach_detach_callback, (Il2CppThreadAttachCallback attach, Il2CppThreadAttachCallback detach));`r`n")
}

$il2cpp_api = Join-Path $sourceCodeDir libil2cpp/il2cpp-api.cpp
$content = Get-Content -Path $il2cpp_api
$match = $content | Select-String -Pattern 'il2cpp_set_thread_attach_detach_callback'
# Write-Host $content
if($match.Matches.Count -eq 0)
{
    $content = $content.Replace('Il2CppThread *il2cpp_thread_attach(Il2CppDomain *domain)', 'Il2CppThread *il2cpp_thread_attach_deprecated(Il2CppDomain *domain)')
    $content = $content.Replace('void il2cpp_thread_detach(Il2CppThread *thread)', 'void il2cpp_thread_detach_deprecated(Il2CppThread *thread)')
    $content = $content.Replace('// thread', `
        (
"// thread 
static Il2CppThreadAttachCallback attach_callback;
static Il2CppThreadAttachCallback detach_callback;

void il2cpp_set_thread_attach_detach_callback(Il2CppThreadAttachCallback attach, Il2CppThreadAttachCallback detach)
{
    attach_callback = attach;
    detach_callback = detach;
}
Il2CppThread *il2cpp_thread_attach(Il2CppDomain *domain)
{
    Il2CppThread* thread = Thread::Attach(domain);
    if(attach_callback != nullptr)
    {
        attach_callback(thread);
    }
    return thread;
}

void il2cpp_thread_detach(Il2CppThread *thread)
{
    if(detach_callback != nullptr)
    {
        detach_callback(thread);
    }
    Thread::Detach(thread);
}"))

    Set-Content -Path $il2cpp_api $content
}

# Modify Thread Signal 
$gcPrivPath = Join-Path $sourceCodeDir external/bdwgc/include/private/gc_priv.h
$content = Get-Content -Path $gcPrivPath
Write-Host $content
$destContent = '#   define SIG_THR_RESTART SIGRTMIN + 5 //SIG_THR_RESTART SIGXCPU'
$match = $content | Select-String -Pattern $destContent
if($match.Matches.Count -eq 0)
{
    $content = $content.Replace('#   define SIG_THR_RESTART SIGXCPU', $destContent)
    Write-Host 'Set SIG_THR_RESTART from SIGXCPU to SIGRTMIN + 5'
}

$pthreadStopWorldPath = Join-Path $sourceCodeDir external/bdwgc/pthread_stop_world.c
$content = Get-Content -Path $pthreadStopWorldPath
$destContent = '#     define SIG_SUSPEND SIGRTMIN + 6 //SIG_SUSPEND SIGPWR'
$match = $content | Select-String -Pattern $destContent
if($match.Matches.Count -eq 0)
{
    $content = $content.Replace('#     define SIG_SUSPEND SIGPWR', $destContent)
    Write-Host 'Set SIG_SUSPEND from SIGPWR to SIGRTMIN + 6'
}

