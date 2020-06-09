/* Subject: compute the n powers of 2 for any non-negative integer n, with no shift operation more than one digit */

/* This is the English annotation I wrote, according to my own understanding, 
   if you want to query the Chinese annotation (中文注释), please move to https://dsa.cs.tsinghua.edu.cn/~deng/ds/src_link/power/power2-0-i.cpp.htm

   Tips: T(n) = O(n) = O(2^r) [r is the size of exponent n in bits ] - "for n is linear-time algorithm", "for r is exponential-time algorithm"
*/

#include <iostream>  // __int64, cout

using namespace std;

__int64 power2BF_I( int n ){    
    long long pow = 1;  // "__int64" type is similar to "long long", 8 bytes
    while( 0 < n -- ){
        pow <<= 1;  // 'pow = pow << 1' equals to 'pow = pow * 2'
    }
    return pow;
}

int main(){

    int n = 50;
    long long pow = power2BF_I(n);

    cout << "power2BF_I(n) =\t" << pow <<endl;

}

/*
    process: 50(d) = 32 + 16 + 2(d) = 110010(b)

    result: power2BF_I(n) = 1125899906842624 = 2^50

    tips: 2^6 < 50 < 2^7, r =  rounded down(log_2 50) + 1  = 6 + 1 = 7 

*/