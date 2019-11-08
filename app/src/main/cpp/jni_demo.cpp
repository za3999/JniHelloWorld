//
// Created by 郑先生 on 2019-11-07.
//

#include <jni.h>

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_jnihelloworld_jni_Jni_getInt(JNIEnv *env, jobject jobj) {
    return 3;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_jnihelloworld_jni_Jni_add(JNIEnv *env, jobject jobj, jint a, jint b) {
    return a + b;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_jnihelloworld_jni_Jni_getUserName(JNIEnv *env, jobject thiz, jobject user) {
    jmethodID mid = env->GetMethodID(env->GetObjectClass(user), "getName", "()Ljava/lang/String;");
    jstring str = static_cast<jstring>(env->CallObjectMethod(user, mid));
    return str;
}