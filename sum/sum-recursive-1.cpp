/* Question: calculate the sum of the given n integers in a recursive method */
  
/* For Chinese annotation, https://dsa.cs.tsinghua.edu.cn/~deng/ds/src_link/sum/sum2.cpp.htm */

#include <iostream> // std:out

using namespace std;

int sum( int *A, int lo, int hi ){
    if( lo == hi ){  
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

*/


