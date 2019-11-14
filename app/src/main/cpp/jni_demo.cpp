//
// Created by 郑先生 on 2019-11-07.
//

#include <jni.h>
#include "util.cpp"

static const char *className = "com/example/jnihelloworld/jni/Jni";

static int getInt(JNIEnv *env, jobject jobj) {
    return 3;
}

static int add(JNIEnv *env, jobject jobj, jint a, jint b) {
    return a + b;
}

static jstring getUserName(JNIEnv *env, jobject jobj, jobject user) {
    jmethodID mid = env->GetMethodID(env->GetObjectClass(user), "getName", "()Ljava/lang/String;");
    jstring str = static_cast<jstring>(env->CallObjectMethod(user, mid));
    return str;
}

static JNINativeMethod jni_Methods_table[] = {
        {"getInt",      "()I",                                                       (void *) getInt},
        {"add",         "(II)I",                                                     (void *) add},
        {"getUserName", "(Lcom/example/jnihelloworld/bean/User;)Ljava/lang/String;", (void *) getUserName},
};

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env = NULL;
    if ((vm)->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }
    // 判断类名是否正确
    jclass clazz = (env)->FindClass(className);
    if (clazz == NULL) {
        return JNI_ERR;
    }

    //开始注册
    jint ret = (env)->RegisterNatives(clazz, jni_Methods_table, getArrayLen(jni_Methods_table));
    if (ret != JNI_OK) {
        return JNI_ERR;
    }
    (env)->DeleteLocalRef(clazz);
    return JNI_VERSION_1_6;
}

