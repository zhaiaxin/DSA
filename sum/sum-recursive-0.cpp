/* Question: calculate the sum of the given n integers in a recursive method */
  
/* For Chinese annotation, https://dsa.cs.tsinghua.edu.cn/~deng/ds/src_link/sum/sum1.cpp.htm */

#include <iostream>  // cout

using namespace std;

int sum( int A[], int n ){
    if( n < 1){
        return 0;  // base case of recursion
    }
    return sum( A, n - 1 ) + A[n - 1];  // sum( A, n - 1 ) calls its self
}

int main(){
    
    int A[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof( A ) / sizeof( *A );  // sizeof(): return the size of data type in bytes

    cout << sum( A, n ) << endl;
}

/* Time Complexity: O(n) - "linear-time algorithm" */