#include "vector.h"

template <typename T> int Vector<T>::remove( Rank lo, Rank hi ){  // 删除区间[lo,hi)
    if( lo == hi ) return 0;  // 此时删除区间相当于 [lo,lo), 显然无意义
    while( hi < _size ) _elem[lo++] = _elem[hi++];  // [hi,_size)顺次前移 hi-lo 个单元
    _size = lo;  // 更新规模, 因为随着`while( hi < _size ) _elem[lo++] = _elem[hi++]`的执行, 当跳出循环时,
                 // lo == (n - hi) + lo, 即 [hi,n) 区间中元素的数目加上初始的 lo 值
    shrink();  // 若有必要, 则进行缩容
    return hi - lo;  // 返回被删除元素的数目
}

template <typename T> T Vector<T>::remove( Rank r ){  // 删除向量中秩为 r 的元素, 0 <= r <= size
    T e = _elem[r];  // 备份被删除的元素
    remove( r, r + 1 );  // 删除区间[r,r+1), 其实就是删除了单个元素 _elem[r]
    return e;
}