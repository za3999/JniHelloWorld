package com.example.jnihelloworld.jni;

public class Jni {

    static {
        System.loadLibrary("jni_demo");
    }

    public native int getInt();

    public native int add(int a, int b);
}
