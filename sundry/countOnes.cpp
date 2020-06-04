/* Subject: for any non-negative integer, count the number of digits 1 in its binary expansion */

/* This is the English annotation I wrote, according to my own understanding, 
   if you want to query the Chinese annotation (中文注释), please move to https://dsa.cs.tsinghua.edu.cn/~deng/ds/src_link/countones/countones.cpp.htm
 
   Tips: T(n) = O(n) 
*/

#include "../utility.cpp"   // printArray()

using namespace std;

int countOnes(unsigned int n){
    int ones = 0;
    while( n > 0 ){
        /*  In comparison to the follow code statement, it costs extra time for jugding
        if( n & 1 == 1){
            ones++;
        }
        */
        ones += ( n & 1);   // &: bit operation "AND", it will operate the binary form of two numbers
        n >>= 1;
    }
    return ones;
}

int main(){
    
    int A[] = { 15, 14, 12, 8 }; 
    int n = sizeof(A)/sizeof(*A);   // sizeof(): return the size of data type in bytes

    int ones[n];

    for(int i = 0; i < n; i++){
        ones[i] = countOnes(A[i]);
    }

    printArray( ones, n );

}

/*
    analysis:

        15(d) = 1111(b) 
        14(d) = 1110(b) 
        12(d) = 1100(b)
        8(d)  = 1000(b)

    result: 4 3 2 1

    */