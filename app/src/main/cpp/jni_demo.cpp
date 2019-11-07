//
// Created by 郑先生 on 2019-11-07.
//

#include <jni.h>

extern "C" JNIEXPORT jint JNICALL
Java_com_example_jnihelloworld_jni_Jni_getInt(JNIEnv *env, jobject jobj) {
    return 3;
}

extern "C" JNIEXPORT jint JNICALL
Java_com_example_jnihelloworld_jni_Jni_add(JNIEnv *env, jobject jobj, jint a, jint b) {
    return a + b;
}
