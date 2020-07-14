#include "vector.h"

template <typename T> void Vector<T>::unsort( Rank lo, Rank hi ){
    T* V = _elem + lo;  // 将子向量 _elem[lo, hi) 视作另一向量 V[0, hi-lo), 即给子向量 _elem[lo, hi) 区间左移 lo 个单位
    for( Rank i = hi - lo; i > 0; i-- ){  // 自后往前
        swap( V[i - 1], V[rand() % i ] );  // // 将 V[i-1] 与 V[0, i) 中某一随机元素交换
    }
}