#include "vector.h"

template <typename T>  // 由于有序向量是非减的, 故需要找到 小于或等于e 的最后一个节点的秩
Rank Vector<T>::search( T const& e, Rank lo, Rank hi ) const {
    return ( rand() % 2 ) ? binSearch( _elem, e, lo, hi ) : fibSearch( _elem, e, lo, hi );  // 按50%的概率随机使用二分或fibonacci查找
}