/* Question: sort an array in positive order */
  
/* For Chinese annotation, https://dsa.cs.tsinghua.edu.cn/~deng/ds/src_link/bubblesort/bubble1a.cpp.htm */

/* To see the process in the TERMINAL, remove the 1'and 2' comments */

#include <utility>  // std:swap()

#include "../utility.cpp"  // printArray()

using namespace std;

void bubbleSort( int A[], int n ){ 

    int size = n;  // 1': get the size of A[] 

    bool sorted = false;  // Default value - 'false' : the A[] is NOT sorted
    while( !sorted ){  // it loops until A[] is sorted
        
        printArray( A, size );  // 2': print all the elements in A[]
        
        sorted = true;  // Assuming the A[] is in order
        for( int i = 1; i < n; i++ ){  // perform ONE bubble sort
            if( A[i-1] > A[i] ){
                swap( A[i-1], A[i] );
                sorted = false;  // a.由于经过 n-1 次排序后, 才能认为 A[n] 已经排好序, 但如果进入 for{} 循环, 此时已排序次数必然小于 n
                                 // b.若将 'sorted = false' 放在 if{} 外, for{} 中, 那么假定原序列本身整体有序, 
                                 //   本来进行 1 次 for{} 比较即可, 却需要额外进行 n-2 次 for{}
            }   
        }
        n--;  // Each time the loop is finished, one element will be placed in its final position.
    }
}  // Better than for{for{}}, it can break the loop ASAP.

int main(){

    int A[] = { 5, 2, 7, 4, 6, 3, 1 };
    int n = sizeof( A ) / sizeof( *A );  // sizeof(): return the size of data type in bytes. 

    bubbleSort( A, n );

}

/* 
    Process:                         稳定排序
              5 2 7 4 6 3 1
        a:    2 5 4 6 3 1 7
        b:    2 4 5 3 1 6 7
        c:    2 4 3 1 5 6 7                
        d:    2 3 1 4 5 6 7
        e:    2 1 3 4 5 6 7
        f:    1 2 3 4 5 6 7

    Time Complexity: O(n^2) - "polynomial-time algorithm"
*/