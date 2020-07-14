/* 题目：对于任意非负整数, 统计其二进制展开中 数位1 的总数*/

/* 详解：http://dsa.cs.tsinghua.edu.cn/~deng/ds/src_link/countones/countones_1.cpp.htm */

#include "../utility.cpp"

using namespace std;

int countOnes( int n ){
    int ones = 0;  // 数位1 的总数
    while( n > 0 ){  // n > 0 时, 将 n 用二进制表示，其中数位1的总数至少为 1 个, 例: n = 1  
        ones ++;  
        n &= ( n - 1 );  // 通过 'n &= ( n - 1 )' 可以消去最右边的 数位1, 见习题册p8

    }
    return ones;
}

int main(){
    int A[] = { 15, 14, 12, 8 }; 
    int n = sizeof( A ) / sizeof( *A );   

    int ones[n];

    for(int i = 0; i < n; i++){
        ones[i] = countOnes( A[i] );
    }

    printArray( ones, n );

}

/*
    分析:                   结果: 4 3 2 1

        15(d) = 1111(b) 
        14(d) = 1110(b) 
        12(d) = 1100(b)
        8(d)  = 1000(b)

    时间复杂度: O(r), r 是十进制数 n 的二进制表示中，数位1 的个数。

*/