#include "vector.h"

template <typename T> 
Rank Vector<T>::insert( Rank r, T const& e ){
    expand();  // 若有必要, 则扩容
    for(int i = _size; i > r; i-- ) _elem[i] = _elem[i-1];  // 自后向前, 后继元素顺次后移一个单元
                                                            // 数据域范围:[0, _size), 故 _elem[size] 是空数据域的第一个元素
                                                            // 最后一次循环`i = r + 1`, `_elem[r+1]=_elem[r]`
    _elem[r] = e; _size++;  // 置入新的元素, 并更新容量
    return r;  // 返回秩
}