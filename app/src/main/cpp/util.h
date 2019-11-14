//
// Created by 郑先生 on 2019-11-14.
//

template<class T>
int getArrayLen(T &array) {
    return (sizeof(array) / sizeof(array[0]));
}
