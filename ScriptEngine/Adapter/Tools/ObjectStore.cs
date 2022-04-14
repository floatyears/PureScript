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
    private static extern object GetObject(IntPtr ptr);
    [MethodImpl(MethodImplOptions.InternalCall)]
    private static extern IntPtr GetObjectPtr(object obj);

    [MethodImpl(MethodImplOptions.InternalCall)]
    public static extern void GetReturnArrayMono(Array src, ref IntPtr dest);

    [MethodImpl(MethodImplOptions.InternalCall)]
    public static extern void GetReturnStructMono(IntPtr src, ref IntPtr dest, Type structType, int size);

    public static IntPtr Store(object obj)
    {
        if (obj == null)
            return IntPtr.Zero;

        return GetObjectPtr(obj);
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static T Get<T>(IntPtr handle) where T : class
    {
        if (handle == IntPtr.Zero)
            return null;

        var obj = GetObject(handle);
        return obj as T;
    }

}