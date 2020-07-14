/* Question: for any non-negative integer, count the number of digits 1 in its binary expansion */
  
/* For Chinese annotation, go to https://dsa.cs.tsinghua.edu.cn/~deng/ds/src_link/countones/countones.cpp.htm */
  
#include "../utility.cpp"   // printArray()

using namespace std;

int countOnes( unsigned int n ){
    int ones = 0;
    while( n > 0 ){
        /*  In comparison to the follow code statement, it costs extra time for jugding
        if( n & 1 == 1){
            ones++;
        }
        */
        ones += ( n & 1 );   // &: 将两个操作数转换为 二进制 进行 "与运算", 1 & 1 = 1, 0 & 1 = 1, 
                             //    故 '( n & 1 )' 数值上等于 n 二进制形式的最低位, 且 0 对计算结果没有影响
        n >>= 1;
    }
    return ones;
}

int main(){
    
    int A[] = { 15, 14, 12, 8 }; 
    int n = sizeof( A ) / sizeof( *A );   // sizeof(): return the size of data type in bytes

    int ones[n];

    for(int i = 0; i < n; i++){
        ones[i] = countOnes( A[i] );
    }

    printArray( ones, n );

}

/*
    analysis:                   result: 4 3 2 1

        15(d) = 1111(b) 
        14(d) = 1110(b) 
        12(d) = 1100(b)
        8(d)  = 1000(b)

    Time Complexity: O(logn) = O(r) , r 是非负整数 n 二进制的位数



*/