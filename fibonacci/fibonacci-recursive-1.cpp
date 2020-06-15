/* 题目：用递归（线性）求解 fibonacci 数列第 n 项 */

/* 详解：http://dsa.cs.tsinghua.edu.cn/~deng/ds/src_link/fibonacci/fib2.cpp.htm */

#include <iostream>

using namespace std;

__int64 fib( int n, __int64& prev ){ // '__int64& prev' 中的 '& 是引用, 因为 prev 要指向 自身的递归调用
    if ( n == 0 )  
       { prev = 1; return 0; }  // prev = fib(-1) = 1, fib( 0, prevPrev ) = fib(0) = 0
    else {
        __int64 prevPrev; 
        prev = fib ( n - 1, prevPrev );  // prev 存放着 前一项的计算结果
        cout << prevPrev << " " << prev << endl;
        return prevPrev + prev;
    }
}

int main(){

    int n = 4;
    __int64 prev; // 取值对于最终结果无任何影响，只是形式上需要而已

    cout << fib ( n , prev ) << endl;
}

/*
    分析过程: 

        fibonacci: 1(index = -1), 0, 1, 1, 2, 3, 5, 8, ...

        "cout << prevPrev << " " << prev << endl" 输出结果为：

                1 0
                0 1
                1 1
                1 2

                可发现其实, prevPrev = fib(k-1), prev = fib(k)


        当调用 fib(4,prev) 时, 语句的执行顺序:

            a. prev = fib ( 3, prevPrev )

            b. prev = fib ( 2, prevPrev )

            c. prev = fib ( 1, prevPrev )

            d. prev = fib ( 0, prevPrev ); prevPrev = 1 且 prev = fib( 0, prevPrev ) = 0

            e. 此时，开始消去已有的递归，先回到 

                prev = fib ( 1, 1 ) = prevPrev + prev = 1 + 0 = 1

                prev = fib ( 2, 0 ) = prevPrev + prev = 0 + 1 = 1

                prev = fib ( 3, 1 ) = prevPrev + prev = 1 + 1 = 2

        总结：

            这种思路可以减少重复计算的情况，进而提升算法的效率。

*/