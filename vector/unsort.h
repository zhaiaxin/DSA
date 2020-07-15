#include "vector.h"

template <typename T> void Vector<T>::unsort( Rank lo, Rank hi ){
    /*
        指针算术:

            例:

                double* p3 = new double[3];  // 指针p3, 作为double数组名来使用
                double array[3] = {0.2, 0.5, 0.8}

                p3[0] = 0.2;  // 第一个元素 p3[0]
                p3[1] = 0.5;  // 第二个元素 p3[1]
                p3[2] = 0.8;  // 第三个元素 p3[2]
                
                p3 = p3 + 1;  // 数组名array, 不可以进行修改; 但使用指针作为数组名时, 
                              // 则可以修改且此时 p3[0] = 0.5, p3[1] = 0.8, 相当于将数组左移了 1 个单位
    
    */
    T* V = _elem + lo;  // 将子向量 _elem[lo, hi) 视作另一向量 V[0, hi-lo), 即给子向量 _elem[lo, hi) 区间左移 lo 个单位
    for( Rank i = hi - lo; i > 0; i-- ){  // 自后往前
        swap( V[i - 1], V[rand() % i ] );  // // 将 V[i-1] 与 V[0, i) 中某一随机元素交换
    }
}