/* Subject: calculate the sum of the given n integers */

/* This is the English annotation I wrote, according to my own understanding, 
   if you want to query the Chinese annotation (中文注释), please move to https://dsa.cs.tsinghua.edu.cn/~deng/ds/src_link/sum/sum0.cpp.htm
 
   Tips: T(n) = O(n) - "linear-time algorithm"
*/

#include <iostream>  // cout

using namespace std;

// sumI is the abbreviation of sumIntegers
int sumI( int A[], int n ){
    int sum = 0;
    for( int i = 0; i < n; i++ ){
        sum += A[i];
    }
    return sum;
}

int main(){

    int A[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof( A ) / sizeof( *A );  // sizeof(): return the size of data type in bytes

    int sum = sumI( A, n );
    cout << sum << endl;
    
}