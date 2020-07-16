#include "vector.h"

template <typename T> int Vector<T>::disordered() const {  // 统计向量中逆序相邻元素对的总数
    int n = 0;
    for( int i = 1; i < _size; i++ ){
        if( _elem[i-1] > _elem[i] ) n++;
    }
    return n;
}