/* 题目：在禁止超过 1 位运算的前提下, 对任意非负整数 n , 计算幂 2^n */

/* 详解：http://dsa.cs.tsinghua.edu.cn/~deng/ds/src_link/power/power2-0-r.cpp.htm*/

#include <iostream>

using namespace std;

__int64 power( int n ){
    return ( n < 1 ) ? 1 : power( n - 1 ) << 1;  // 2^0 = 1, 故这里也可将其 '( n < 1 )' 改为 '( n = 0 )'
}

int main(){
     
     int n = 5;
     
     cout << power(n) << endl;
}

/*
    结果: 32

    时间复杂度: O(n) = O(2^r) , r 是 n 二进制形式的位数

               递推方程法: 
               
                    T(n) = T(n-1) + O(1) = T(n-1) + c1 , 左移位运算时间复杂度为常数级 O(1) 

                    T(0) = O(1) = c2 , return 1 时间复杂度也为常数级 O(1)

                    经过递推得, T(n) = T(n-1) + c1 = T(n-2) + 2 * c1 = ... = c1 * n + c2 , 即 o(n)

    空间复杂度: O(n) , 存在 n 个递归实例 
*/
