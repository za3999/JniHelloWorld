package com.example.jnihelloworld.jni;

import com.example.jnihelloworld.bean.User;

public class Jni {

    static {
        System.loadLibrary("jni_demo");
    }

    public native int getInt();

    public native String getJniUser();

    public native int add(int a, int b);

    public native String getUserName(User user);
}
