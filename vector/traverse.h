#include "vector.h"

/*
    函数指针: 使得可以在不同的时间传递不同的值

        例:
            double func (int);  // 定义了一个 int参数, double返回值 的函数func
            double (*funcp) (int);  // 定义了一个 int参数, double返回值 的函数指针funcp
            funcp = func;  // 将 func 赋值给 funcp, 这样 `func(1)` 与 `funcp(1)` 作用相同

*/
template <typename T> void Vector<T>::traverse( void (*visit) ( T& ) ){  // `void (*visit) ( T& )` 定义了一个 T& 参数, void 返回值的函数指针 visit
    for( int i = 0; i < _size; i++ ) visit( _elem[i] );  // 遍历向量
}

//////??????????????
template <typename T> template <typename VST>  // 元素类型, 操作器：为什么有两个模板, 且和上面的区别在哪
void Vector<T>::traverse( VST& visit ){
    for( int i = 0; i < _size; i++) visit( _elem[i] );  // 遍历向量
}