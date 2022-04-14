using UnityEngine;
using System.Runtime.InteropServices;
using AOT;
using System;

namespace PureScript
{
    public class ScriptEngine
    {

        const string XMONO_LIB = "__Internal";

        //const string XMONO_LIB = "ScriptEngine";


        [DllImport(XMONO_LIB, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr GetFuncPointer();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void OnException(Exception e);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void CheckException();
    }
}

