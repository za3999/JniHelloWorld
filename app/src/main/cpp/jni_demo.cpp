//
// Created by 郑先生 on 2019-11-07.
//

#include <jni.h>

typedef void *pVoid;
static const char *className = "com/example/jnihelloworld/jni/Jni";

static int getInt(JNIEnv *env, jobject jobj) {
    return 3;
}

static int add(JNIEnv *env, jobject jobj, jint a, jint b) {
    return a + b;
}

static jstring getUserName(JNIEnv *env, jobject thiz, jobject user) {
    jmethodID mid = env->GetMethodID(env->GetObjectClass(user), "getName", "()Ljava/lang/String;");
    jstring str = static_cast<jstring>(env->CallObjectMethod(user, mid));
    return str;
}

static JNINativeMethod jni_Methods_table[] = {
        {"getInt",      "()I",                                                       (void *) getInt},
        {"add",         "(II)I",                                                     (void *) add},
        {"getUserName", "(Lcom/example/jnihelloworld/bean/User;)Ljava/lang/String;", (void *) getUserName},
};

static int jniRegisterNativeMethods(JNIEnv *env, const char *className) {
    jclass clazz;

    clazz = (env)->FindClass(className);
    if (clazz == NULL) {
        return -1;
    }

    int result = 0;
    int numMethods = sizeof(jni_Methods_table) / sizeof(JNINativeMethod);
    if ((env)->RegisterNatives(clazz, jni_Methods_table, numMethods) < 0) {
        result = -1;
    }

    (env)->DeleteLocalRef(clazz);
    return result;
}

jint JNI_OnLoad(JavaVM *vm, pVoid reserved) {

    JNIEnv *env = NULL;
    jint result = -1;

    if (vm->GetEnv((void **) &env, JNI_VERSION_1_4) != JNI_OK) {
        return result;
    }

    jniRegisterNativeMethods(env, className);
    return JNI_VERSION_1_4;
}

