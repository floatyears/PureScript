//#define WRAPPER_SIDE
using AOT;
using System;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

internal static class ObjectStore
{

    [MethodImpl(MethodImplOptions.InternalCall)]
    public static extern object GetObject(IntPtr ptr);
    
    [MethodImpl(MethodImplOptions.InternalCall)]
    private static extern IntPtr GetObjectPtr(object obj);

    [MethodImpl(MethodImplOptions.InternalCall)]
    public static extern void GetReturnArrayToMono(Array src, ref IntPtr dest);

    [MethodImpl(MethodImplOptions.InternalCall)]
    public static extern void GetReturnStructToMono(IntPtr src, ref IntPtr dest, Type structType, int size);

    [MethodImpl(MethodImplOptions.InternalCall)]
    public static extern IntPtr ConvertObjectIl2CppToMono(object obj);

    public static IntPtr Store(object obj)
    {
        // if (obj == null)
        // {
        //     UnityEngine.Debug.LogError("ObjectStore.Store() obj is null");
        //     return IntPtr.Zero;
        // }

        return GetObjectPtr(obj);
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static T Get<T>(IntPtr handle) where T : class
    {
        // if (handle == IntPtr.Zero)
        // {
        //     UnityEngine.Debug.LogError("ObjectStore.Get() handle is IntPtr.Zero");
        //     return null;
        // }

        var obj = GetObject(handle);
        return obj as T;
    }

}