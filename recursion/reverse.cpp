/* Subject: sort an array in positive order */

/* This is the English annotation I wrote, according to my own understanding, 
   if you want to query the Chinese annotation (中文注释), please move to http://dsa.cs.tsinghua.edu.cn/~deng/ds/src_link/reverse/reverse.cpp.htm , http://dsa.cs.tsinghua.edu.cn/~deng/ds/src_link/reverse/reverse-recursive.cpp.htm
 
   Tips: T(n) = O(n) - "linear-time algorithm"
*/

#include <utility>  // swap()

#include "../utility.cpp" // printArray()

using namespace std;

/* 
    if you comment this code, you will see errors in TERMINAL,
    because the code in next overload function 'reverse( int A[], int n )' will call itself,
    but they have different parameters.

    you can also put 'reverse( int* A, int lo, int hi )' in the front of 'reverse( int A[], int n )' to solve this problem.
*/
void reverse( int*, int, int );  

void reverse( int A[], int n ){  // the initial entry called by the reverse() in main()
    reverse( A, 0, n-1 );  // function
}

/* Recursive type */
void reverse( int* A, int lo, int hi ){  
    if( lo < hi ){
        swap( A[lo], A[hi] );
        reverse( A, lo + 1, hi - 1 );
    }   // the hidden 'else' include "lo == hi" and "lo > hi"
}

int main(){
    
    int A[] = { 1, 2, 3, 4, 5, 6 };  //  even: the terminal condition is "lo(3) > high(2)"
    int A_n = sizeof( A ) / sizeof( *A );

    int B[] = { 1, 2, 3, 4, 5 };  //  odd: the terminal condition is "lo(2) = high(2)"
    int B_n = sizeof( B ) / sizeof( *B );

    reverse( A, A_n );
    reverse( B, B_n );

    printArray( A, A_n );
    printArray( B, B_n);

}