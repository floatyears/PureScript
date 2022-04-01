echo --------------Build Pure Script Start----------------

set NDK_ROOT="E:\Software\android-ndk-r21d-windows-x86_64\android-ndk-r21d"

cd /d %~dp0
set /a startsecond=time:~0,1%*10+%time:~1,1%)*3600+(%time:~3,1%*10+%time:~4,1%)*60+(%time:~6,1%*10+%time:~7,1%)
set ScriptEnginePath=%~dp0\..
set AndroidPath=%~dp0
echo %ScriptEnginePath%
set BuildPath=%~dp0\build

rd /q /s %BuildPath%\jni
rd /q /s %BuildPath%\libs\armeabi-v7a
rd /q /s %BuildPath%\obj\local\armeabi-v7a
rd /q /s %BuildPath%\libs\arm64-v8a
rd /q /s %BuildPath%\obj\local\arm64-v8a

md %BuildPath%\jni
md %BuildPath%\jni\cusotm
md %BuildPath%\jni\generated
md %BuildPath%\jni\main
md %BuildPath%\lib

xcopy /s /e /q %ScriptEnginePath%\custom %BuildPath%\jni\custom\
xcopy /s /e /q %ScriptEnginePath%\generated %BuildPath%\jni\generated\
xcopy /s /e /q %ScriptEnginePath%\main %BuildPath%\jni\main\
xcopy /s /e /q %ScriptEnginePath%\lib\include %BuildPath%\jni\include\
xcopy /s /e /q /Y %ScriptEnginePath%\lib\Android\* %BuildPath%\lib\

copy /Y %ScriptEnginePath%\ScriptEngine.c %BuildPath%\jni\

copy /Y %AndroidPath%\Android.mk %BuildPath%\jni\Android.mk
copy /Y %AndroidPath%\Application.mk %BuildPath%\jni\Application.mk

cd %BuildPath%\jni

set CPP_ADDITIONAL_MACROS=""
echo CPP_ADDITIONAL_MACROS=%CPP_ADDITIONAL_MACROS%

if "%NDK_DEBUG%" == "1" (
echo NDK_DEBUG=1
set DEBUG_CMD="NDK_DEBUG=1"
) else (
echo NDK_DEBUG=0
set DEBUG_CMD="NDK_DEBUG=0"
)

call %NDK_ROOT%\ndk-build clean
call %NDK_ROOT%\ndk-build -j 16 "%DEBUG_CMD%" MY_ADDITIONAL_MACROS="%CPP_ADDITIONAL_MACROS%"

if "%errorlevel%" NEQ "0" (
echo "C++ Compile Failed!!"
exit /B %errorlevel%
) else (
echo "C++ Compile Success!!"
@REM copy /Y %BuildPath%\libs\armeabi-v7a\* %GameCorePath%\..\Project\Assets\Plugins\Android\libs\armeabi-v7a\
)