/* Question: calculate the sum of the given n integers in a recursive method */
  
/* For Chinese annotation, https://dsa.cs.tsinghua.edu.cn/~deng/ds/src_link/sum/sum2.cpp.htm */

#include <iostream> // std:out

using namespace std;

int sum( int *A, int lo, int hi ){
    if( lo == hi ){  // base
        return A[lo];  // Also 'A[hi]'
    }else{
        int mi = (lo + hi) >> 1; 
        return sum( A, lo, mi ) +sum( A, mi + 1, hi);  // binary recursion
    }
}

int main(){

    int A[] = { 0, 1, 2, 3, 4, 5 };
    int n = sizeof( A ) / sizeof( *A );  

    cout << sum ( A, 0, n-1 ) << endl;
}
/*
    process:
                            sum(0,5)
                            
                      sum(0,2)    sum(3,5)

              sum(0,1) sum(2,2)  sum(3,4) sum(5,5)

          sum(0,0) sum(1,1)     sum(3,3) sum(4,4)

    
    result: 15

    Time Complexity: O(n) - "linear-time algorithm"  
    
        分析技巧：先划去 return 中的递归调用语句，发现不包括任何 显示或隐式 的迭代，即 每一个递归实例，无论区间长短，总是对应着 O(1) 时间。

                故只需要统计所有递归实例的总数（即二叉树结点数），
                
                T(n) = 各层递归实例所需时间之和 = O(1) * (2^0 + 2^1 + ... + 2^(logn))，是一个几何级数（时间复杂度与末项同阶）
                 
                在渐进的角度分析问题规模，发现递归实例 与 递归基的个数( sum(0,0), sum(1,1),...) 成比例，故 T(n) = O(n)

*/


