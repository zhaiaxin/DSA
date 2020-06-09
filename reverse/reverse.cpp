/* This is the English annotation I wrote, according to my own understanding, 
   if you want to query the Chinese annotation (中文注释), please move to http://dsa.cs.tsinghua.edu.cn/~deng/ds/src_link/reverse/reverse.cpp.htm
*/

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
