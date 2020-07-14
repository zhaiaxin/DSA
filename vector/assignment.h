#include "vector.h"

template <typename T> 
Vector<T>& Vector<T>::operator= ( Vector<T> const& V ){  // 重载赋值操作
    if( _elem ) delete [] _elem;  // 释放原有内容, 若 _elem != 0, 则将其数据区清空
    copyFrom( V._elem, 0, V.size() );  // 整体复制, V.size() 返回当前变量的规模
    /*
        this 指针: 指向用来调用成员函数的对象, 被作为隐藏参数传递方法
            
            但下面语句的具体含义还是有点搞不懂
    */
    return *this;  // 返回当前对象的引用
}
