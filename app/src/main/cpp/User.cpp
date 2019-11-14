#include <jni.h>

//
// Created by 郑先生 on 2019-11-14.
//
class User {
private:
    jstring mName;
    int mNumber;
public:

    User(jstring name, int number) {
        mName = name;
        mNumber = number;
    }

    const jstring getName() {
        return mName;
    }

    int getNumber() {
        return mNumber;
    }
};

