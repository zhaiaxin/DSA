/* 题目：在禁止超过 1 位运算的前提下, 对任意非负整数 n , 计算幂 2^n */

/* 详解：http://dsa.cs.tsinghua.edu.cn/~deng/ds/src_link/power/power2-1-i.cpp.htm*/

#include <iostream>


using namespace std;

__int64 power2( int n ){  // 与 `power2_recursive.cpp` 算法相同, 区别在于自底向上进行计算
    __int64 pow = 1;  // 1 = 2^0 
    __int64 p = 2;  // 累乘项: 对应各比特位所对应的指数权重: 2^1, 2^2, 2^4, 2^8, 2^16, ...
    while( n > 0 ){
        if( n & 1 ){  // 检查最低位是否为1, 若是则乘上 累乘项
            pow *= p;
        }
        n >>= 1;  // n 右移一位
        p *= p;  // 累乘项自乘
        cout << n << " " << pow << " " << p << endl;  // 这里 n, pow, p 都已经进行相应的处理
    }
    return pow;
}


int main(){

    int n = 5;

    cout << power2(n) << endl;

}


/*
                1                     n = 0
    power2(n) = [power2(n/2)]^2 * 2   n > 0 and odd
                [power2(n/2)]^2       n > 0 and even

    过程:

        n  pow  p
        2   2   4       5是奇数, 故这里 pow = pow * p = 1 * 2 = 2, p = p * p = 2 * 2 = 4
        1   2   16      2是偶数，故这里 p = p * p = 16
        0   32  256     1是奇数，故这里 pow = pow * p = 2 * 16 =32, p = p * p = 16 * 16 =256

        pow(5) = pow(2)^2 * 2

        pow(2) = pow(1)^2

        pow(1) = pow(0)^2 * 2

    时间复杂度: T(n) = O(logn) = O(r), r 是 n 的二进制表示

    空间复杂度: O(1), 仅需要 pow 和 p 两个变量
      
*/