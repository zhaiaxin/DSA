/* 题目：用递归（线性）求解 fibonacci 数列第 n 项 */

/* 详解：http://dsa.cs.tsinghua.edu.cn/~deng/ds/src_link/fibonacci/fib2.cpp.htm */

#include <iostream>

using namespace std;

__int64 fib ( int n, __int64& prev ){ // "TODO" 虽然'__int64& prev' 中的 '& 是引用，但是并不明白实际作用。
    if ( n == 0 )  
       { prev = 1; return 0; }
    else {
        __int64 prevPrev; 
        prev = fib ( n - 1, prevPrev );
        return prevPrev + prev;
    }
}

int main(){

    int n = 4;
    __int64 prev = 5;

    cout << fib ( n , prev ) << endl;
}

/*
    分析过程: 

        fibonacci: 0, 1, 1, 2, 3, 5, 8, ...

*/