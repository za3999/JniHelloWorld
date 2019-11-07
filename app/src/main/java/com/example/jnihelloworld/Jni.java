package com.example.jnihelloworld;

public class Jni {

    static {
        System.loadLibrary("jni_demo");
    }

    public native int getInt();
}
