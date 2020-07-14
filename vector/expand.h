#include "vector.h"

template <typename T> void Vector<T>::expand(){
    if( _size < _capacity ) return;  // 若目前向量的规模还未等于或大于其容量的上限, 则不作处理
    if( _capacity < DEFAULT_CAPACITY ) _capacity = DEFAULT_CAPACITY;  // 向量的容量不能低于默认容量
    T* oldElem = _elem; _elem = new T[_capacity <<= 1];  // 用 oldElem指针 存放原来数据区的地址, 新数据区容量加倍
    for( int i = 0; i < _size; i++ ){
        _elem[i] = oldElem[i];  // 复制原向量的内容(T为基本类型, 或已经重载赋值操作符`=`), 
                                // 因为向量内部含有动态分配的空间, 默认的运算符`=`不足以支持向量之间的直接赋值
    }
    delete [] oldElem;  // 释放空间
}