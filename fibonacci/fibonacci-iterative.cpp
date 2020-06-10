/* 题目：用迭代法（动态规划）求解 fibonacci 数列第 n 项 */

/* 详解：http://dsa.cs.tsinghua.edu.cn/~deng/ds/src_link/fibonacci/fib0.cpp.htm */

#include <iostream>

using namespace std;

// f = fib(k), g = fib(k+1)
__int64 fib ( int n ){
    __int64 f = 1, g = 0;  // 初始化 fib(-1) = f = 1, fib(0) = g = 1, 这样 fib(1) = fib(-1) + fib(0) = 1
    while ( 0 < n-- ){
        g += f;  // 'g += f', 此时 g = fib(k+2) = fib(k+1) + fib(k)
        f = g - f;  //  'f = g - f'，此时 f = fib(k+2) - fib(k) = fib(k+1)
    }  
    return g;
}

int main(){

    int n = 4;

    cout << fib( n ) << endl;

}

/*
    分析过程: 

        fibonacci: 0, 1, 1, 2, 3, 5, 8, 13 ...

            n = 4: f = 0, g = 1;
            n = 3: f = 1, g = 1;
            n = 2: f = 1, g = 2;
            n = 1: f = 2, g = 3;

        fib(4) = 3

    时间复杂度: O(n), 此题用到 动态规划 的思想：从递归基出发，自底而上递推得出各子问题的解，直至最终原问题的解
*/