//
// Created by 郑先生 on 2019-11-07.
//

#include <jni.h>

extern "C" JNIEXPORT jint JNICALL

Java_com_example_jnihelloworld_Jni_getInt(JNIEnv *env, jobject jobj){

return 3;

}
