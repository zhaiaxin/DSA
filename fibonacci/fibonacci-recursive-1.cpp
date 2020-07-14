/* 题目：用递归（线性）求解 fibonacci 数列第 n 项 */

/* 详解：http://dsa.cs.tsinghua.edu.cn/~deng/ds/src_link/fibonacci/fib2.cpp.htm */

#include <iostream>

using namespace std;

/*
    引用: 是已定义的变量的别名, 主要作用是作为函数的形参, 这样函数将使用原始数据, 而非其副本

        例:
            int a = 6;
            int& b = a;  // 这里是将 b 作为 a 的别名, `int&`是一种复合类型, 即指向 int 的引用 
                         // 作用: `&b == &a`, a 和 b 变量的地址都相同; 自然有 `b == a`, b 和 a 的值相同
    
    引用 和 指针 的区别：

        形式上:

            int a = 6;
            int* b = &a;  // 指针需要用 `&a`, 即变量a的地址赋值
            int* b; b = &a;  // 指针可以先声明, 再赋值
            int& c = a;  // 引用直接用 a 赋值, 声明引用时必须初始化(即赋值)

        内容上:

            int& c = a;  // 引用更接近下面的 const指针, 必须在创建时进行初始化, 一旦与某个变量关联起来, 就将一直效忠它
            int* const b = &a;

*/
__int64 fib( int n, __int64& prev ){ // '__int64& prev' 中的 '& 是引用, 因为 prev 要指向 自身的递归调用
    if ( n == 0 )  
       { prev = 1; return 0; }  // prev = fib(-1) = 1, fib( 0, prevPrev ) = fib(0) = 0
    else {
        __int64 prevPrev; 
        prev = fib ( n - 1, prevPrev );  // prev 存放着 前一项的计算结果, prevprev 存放 前两项的计算结果
        cout << n << " " << prevPrev << " " << prev << endl;
        return prevPrev + prev;  // prevprev + prev = fib ( n - 2 ) + fib ( n - 1 )
    }
}

int main(){
 
    int n = 4;
    __int64 num; 
    /*
        当调用 `fib( int n, __int64& prev )`时, prev 就是 num 的引用,即 num 的别名
    */
    cout << fib ( n , num ) << endl;
}

/*
    分析过程:                                                                                          

        fibonacci: 1(index = -1), 0, 1, 1, 2, 3, 5, 8, ...                                      

        "cout << ( n - 1 ) << " " << prevPrev << " " << prev << endl" 输出结果为：                              

                1 1 0
                2 0 1
                3 1 1
                4 1 2

                可发现, fib(1) 对应的前两项 fib(-1) = 1, fib(0) = 0; 
                        fib(2) 对应的前两项 fib(0) = 0, fib(1) = 1;
                        以此类推


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

                                fib(4)

                          fib(2)       fib(3)
                        
                    fib(0)  fib(1)  fib(1)  fib(2)

                                         fib(0)  fib(1)

            其中 fib(0), fib(1), fib(2) 各重复计算了 1, 2, 1 次, 采用 记忆/查表 法, 则不会进行重复计算。

        
        时间复杂度: T(n) = O(n), 即意味着时间复杂度与 第n项fibnacci数列 成正比

*/