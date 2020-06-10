/* Question: compute the n powers of 2 for any non-negative integer n, with no shift operation more than one digit */
  
/* For Chinese annotation, http://dsa.cs.tsinghua.edu.cn/~deng/ds/src_link/power/power2-1-r.cpp.htm */

#include <iostream>  // __int64, cout

using namespace std;

/* 
    inline: usage - to solve the problem of frequent calls to small functions that consume a lot of stack space (stack memory)
            limit - only available for small functions (WITHOUT loop and etc)
*/
inline __int64 sqr( __int64 pow ){ return pow * pow; }

__int64 power2( int n ){
    if( n < 1 ) return 1;
    return ( n & 1) ? sqr( power2( n >> 1 ) ) << 1 : sqr( power2( n >> 1 ) );  // 'n & 1 == 0', even; 'n & 1 == 1', odd 
}

int main(){

    int n = 5;

    cout << "power2():\t" << power2(n) << endl;

}
/*
                1                     n = 0
    power2(n) = [power2(n/2)]^2 * 2   n > 0 and odd
                [power2(n/2)]^2       n > 0 and even

    
    power2(5) = power2(2)^2 * 2 = [power2(1)^2]^2 * 2 = ({[power2(0)^2]*2}^2)^2 * 2 = 2^5 = 32

    O(logn) = O(r) [r is the size of exponent n in bits ] - "for n is logarithmic-time algorithm", "for r is linear-time algorithm"

*/