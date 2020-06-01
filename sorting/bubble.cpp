#include <iostream>
#include <utility>

#include "utility.cpp"

using namespace std;

void bubbleSort( int A[], int n){
    // int size = n;
    bool sorted = false;
    while( !sorted ){
        // printArray( A, size );
        sorted = true;
        for( int i = 1; i < n; i++ ){
            if( A[i-1] > A[i] ){
                swap( A[i-1], A[i] );
            }
            sorted = false;
        }
        n--;
    }
}

int main(){

    int A[] = {5,2,7,4,6,3,1};
    int n = sizeof(A)/sizeof(*A);

    bubbleSort( A, n );

}