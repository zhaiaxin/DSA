/* Question: calculate the sum of the given n integers */
  
/* For Chinese annotation, https://dsa.cs.tsinghua.edu.cn/~deng/ds/src_link/sum/sum0.cpp.htm */

#include <iostream>  // cout

using namespace std;

// sumI is the abbreviation of sumIntegers
int sumI( int A[], int n ){
    int sum = 0;
    for( int i = 0; i < n; i++ ){
        sum += A[i];
    }
    // while( n >= 0 ){  // 这样也可以，不过需要注意 n >= 0 和 -- n
    //     sum += A[--n];
    // }
    return sum;
}

int main(){

    int A[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof( A ) / sizeof( *A );  // sizeof(): return the size of data type in bytes

    int sum = sumI( A, n );
    cout << sum << endl;
    
}

/* Time Complexity: O(n) - "linear-time algorithm" */