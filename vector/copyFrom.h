#pragma once
#include "vector.h"

/*
    指针: 

        指针名 - 地址; * 运算符被称为间接值或解除引用运算符, 将其用于指针, 可以得到该地址处存储的值

        例:

            若 pointer 是一个指针, 则 pointer 指代地址, 而 *pointer 指代存储在该地址处的值

            int num = 6;

            int * p_num; p_num = &num;  // *p_num 和 num 等效, 就像 朗朗 和 我侄子 一样
         // int * p_num = &num;  // 和上面一行等效, 直接会将 指针p_num 初始化为 一个地址

            *p_num = *p_num + 1;  // 此时 *p_num, num 的值变为 7, 就像 给朗朗讲故事 就等于 给阿鑫的侄子讲故事
        
    不同的初始化习惯:

        int* pointer;  // 强调 int* 是一种复合类型, 即指向 int 的指针 

        int *pointer;  // 强调 *pointer 是一个 int 类型, 其实和 `int pointer;` 中的 pointer 无差别 

        int * pt = (int *) 0xB8000000  // 0xB8000000 是一个数字, 而不是地址, 故必须先强制转化为 (int*) 才可赋值

*/
template <typename T>
void Vector<T>::copyFrom ( T const* A, Rank lo, Rank hi ){

    /*
        new 分配的内存块(堆或者自由存储区), 通常与 常规变量(例:int p) 声明分配的内存块(栈的内存区域)不同

            int * pt = new int;  // 在运行阶段, 分配未命名的内存

            int p; int * pt = &p;  // 指针 pt 初始化为变量 p 的地址, 变量 p 在编译阶段分配的有名称的内存, 而指针 pt 只是这段内存的别名

        new 创建动态数组:

            int * p = new int[6];  // 此时, new 返回的(即指针 p 指向)是第一个元素 int[0] 的地址; 释放需要 `delete [] p;`
    */

    _elem[] = new T[_capacity = 2 * ( hi - lo )];  // 分配原向量两倍容量的新区间
    _size = 0;  // 规模清零
    while( lo < hi ){  // A[lo,hi)中所有的元素
        _elem[_size++] = A[lo++];  // 复制至_elem[0, hi - lo)
    }

} 
  