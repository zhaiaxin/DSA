/* Subject: sort an array in positive order */

/* This is the English annotation I wrote, according to my own understanding, 
   if you want to query the Chinese annotation (中文注释), please move to http://dsa.cs.tsinghua.edu.cn/~deng/ds/src_link/reverse/reverse-recursive.cpp.htm
 
   Tips: T(n) = O(n) - "linear-time algorithm"
*/

#include <utility>  // swap()
#include "../utility.cpp" // printArray()
#include "reverse.cpp"  // reverse( int*, int, int ), reverse( int A[], int n )

using namespace std;

/* Recursive type */
void reverse( int* A, int lo, int hi ){  
    if( lo < hi ){
        swap( A[lo], A[hi] );  // Swap the positions of the two elements
        reverse( A, lo + 1, hi - 1 );
    }   // the hidden 'else' includes "lo == hi" and "lo > hi"
}

int main(){
    
    int A[] = { 1, 2, 3, 4, 5, 6 };  //  even: the terminal condition is "lo(3) > high(2)"
    int A_n = sizeof( A ) / sizeof( *A );

    int B[] = { 1, 2, 3, 4, 5 };  //  odd: the terminal condition is "lo(2) = high(2)"
    int B_n = sizeof( B ) / sizeof( *B );

    reverse( A, A_n );
    reverse( B, B_n );

    printArray( A, A_n );
    printArray( B, B_n );

}
/*
    result:
        6 5 4 3 2 1
        5 4 3 2 1
*/