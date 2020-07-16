#include "vector.h"

template <typename T> Rank Vector<T>::find( T const& e, Rank lo, Rank hi ) const {  // 默认条件: 0 <= lo < hi <= _size
    /*
        逻辑与运算`&&` :当左右两个操作数都非零的时候, 返回值为真(1); 否则, 返回假(0)
    */
    while( ( lo < hi-- ) && (e != _elem[hi]) );  // 从后往前, 依次寻找; 这里`&&`左右两个条件中若有一个不满足, 便会执行下一句
    return hi;  // 若 hi < lo, 查找失败; 否则, hi即命中元素的秩
                // 这里分析一下 hi == lo 的情况, 倘若 查找的元素 e == _elem[lo], 因为语句`( lo < hi-- ) && (e != _elem[hi])`
                // 是从左向右执行的, 故虽然 `(e != _elem[hi])`, 但其实在一开始 `hi` 的值就为 `hi-1`
                // 当 `hi = lo + 1`时,  `(e != _elem[hi])` 相当于 `(e != _elem[lo])`, 即 hi = lo
                // 分析 hi < lo 的情况, 当 hi = lo 时, `( lo < hi-- )`条件不满足便会退出, 且伴随着 hi--
}