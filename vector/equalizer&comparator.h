#include "vector.h"

/*
    static 静态类成员函数: 不可以通过对象调用静态成员函数, 也不能使用 this 指针; 只可以使用 类名和作用域解析运算符(::)

        例: Vector<T>::lt( a, b )  // 调用Vector<T>类的静态类成员函数lt(a,b)


*/
template <typename T> static bool lt( T* a, T* b ){  // less than, 这里不知道为什么要写一个指针, 一个引用，难道是指针来对比数组吗？
    return lt( *a, *b );
}

template <typename T> static bool lt( T& a, T& b ){  // less than
    return a < b;  // 顺序: 先比较,再返回; 结果: 为真, 返回1; 为假, 返回0

template <typename T> static bool eq( T* a, T* b ){  // equal, 这里不知道为什么要写一个指针, 一个引用，难道是指针来对比数组吗？
    return eq( *a, *b );
}

template <typename T> static bool eq( T& a, T& b ){  // equal
    return a == b;  // 顺序: 先比较,再返回; 结果: 为真, 返回1; 为假, 返回0
}