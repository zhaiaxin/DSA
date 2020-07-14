#include "vector.h"

template <typename T> void Vector<T>::shrink(){
    if( _capacity < DEFAULT_CAPACITY << 1) return;  // 顺序: 先左移, 后判断; 这里比较目前的容量 和 2倍的默认容量 之间的大小关系
    if( _size << 2 > _capacity ) return;  // 如果目前的规模 大于 容量的 1/4 则不做缩容处理
    T* oldElem = _elem; _elem = new T[_capacity >>= 1];  // 用 oldElem指针 存放原来数据区的地址, 新数据区容量减半
    for( int i = 0; i < _size; i++ ){
        _elem[i] = oldElem[i];  // 复制原向量的内容(T为基本类型, 或已经重载赋值操作符`=`), 
                                // 因为向量内部含有动态分配的空间, 默认的运算符`=`不足以支持向量之间的直接赋值
    }
    delete [] oldElem;  // 释放空间
}