/* Question: to transpose left and right sides of an array */
  
/* For Chinese annotation, http://dsa.cs.tsinghua.edu.cn/~deng/ds/src_link/reverse/reverse-iterative-1.cpp.htm */

#include <utility>  // swap()
#include "../utility.cpp"  // printArray()
#include "reverse.cpp"  // reverse( int*, int, int ), reverse( int A[], int n )

using namespace std;

void reverse( int *A, int lo, int hi ){
    while( lo < hi ){  // using 'while()' to replace 'if()' and 'goto'
        swap( A[lo++], A[hi--] );
    }
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

    Time Complextiy: O(n) - "linear-time algorithm" 
*/