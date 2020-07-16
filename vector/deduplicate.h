#include "vector.h"

template <typename T> int Vector<T>::deduplicate(){
    int oldSize = _size;
    Rank i = 1;
    while( i < _size ){
        ( find( _elem[i], 0, i ) < 0 ) ? i++ : remove( i );  // 在其前缀中找与之雷同者(因为从前往后找,重复元素早已删除,故最多能找到一个)
                                                             // 第一次查找时, i 的秩为 1, 即 i 有 1 个前驱元素即 _elem[0]
                                                             // 若 _elem[1] == _elem[0], 则返回 0; 否则, 返回 -1
                                                             // `find( T const& e, Rank lo, Rank hi )` 作用域为 [lo,hi)
    }
    return oldSize - _size;  // 返回向量规模变化量
}