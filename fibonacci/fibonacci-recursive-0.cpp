/* 题目：用递归求解 fibonacci 数列第 n 项 */

/* 详解：http://dsa.cs.tsinghua.edu.cn/~deng/ds/src_link/fibonacci/fib1.cpp.htm */

#include <iostream>

using namespace std;

__int64 fib ( int n ){
    return ( n < 2 ) ?  
           ( __int64 ) n  // 若 n < 2 , 则fib()到达递归基; 其中 fib(0) = 0, fib(1) = 1
            : fib ( n - 2 ) + fib ( n - 1 );
}

int main(){

    int n = 4;

    cout << fib ( n ) << endl;

}

/*
    分析过程: 

        fibonacci: 0, 1, 1, 2, 3, 5, 8, ...
        
        fib(4) = fib(2) + fib(3) = [fib(0) + fib(1)] + [fib(1) + fib(2)] = [fib(0) + fib(1)] + {fib(1) + [fib(0) + fib(1)]}
                                                                        
                                                                         =  0 + 1 + 1 + 0 + 1 = 3

    时间复杂度: O(2^n) , 
        
        递推方程法:   
        
            递推关系: T(n) = T(n-1) + T(n-2) 

            边界条件: T(0) = 0, T(1) = 1

            故可推出: 由于是二分法，故按照二叉树形式计算，

                                        T(n)

                                   T(n-1)   T(n-2)                          由此可以见该二叉树高度约为 n 层，设根节点为第一层，结点数为 2^n - 1

                             T(n-2) T(n-3)  T(n-3) T(n-4)                   忽略所有的常数项，故 O(n) = 2^n

                            ...   ...   ...   ...   ...  ...

                        T(n-n)  ...   ...   ...   ...  ...  ...  ...

*/