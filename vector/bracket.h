#include "vector.h"

template <typename T> T& Vector<T>::operator[] ( Rank r ) const  // 重载下标操作符 `[]`
{ return _elem[r]; }  // 范围 [0,_size)