#include "vector.h"

template <typename T> int Vector<T>::uniquify() {
    int oldSize = _size; int i = 1;  // 存储原向量的规模
    while( i < _size ){
        _elem[i-1] == _elem[i] ? remove( i ) : i++;  // 若雷同, 则删除后者; 由于是有序变量, 故只需要相邻元素比较即可, 无序变量的话则需要 find(所有的前驱元素)
    }
    return oldSize - _size;  // 若删除了雷同的元素, _size定会发生变化

}

template <typename T> int Vector<T>::uniquify() {
    Rank i = 0, j = 0;
    while( ++j < _size ){  // ++j: 意味着刚开始时, j 为 1, 即是 i 的后一个元素
        if( _elem[i] != _elem[j] ){  // 对雷同元素先全部略过, 直到第一个不同的元素出现
            _elem[++i] = _elem[j];  // 将第一个不同元素的值 赋给 i 紧邻的后一个元素
        }
    }
    _size = ++i; shrink();  // 由于左闭右开区间, [0,_size), 故 _size = i + 1
    return j - i;  // 向量规模变化量: j 一直遍历到最后一个元素了, 而 i 等于 _elem - 1
}