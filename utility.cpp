/*  
    It's a utility class writting for common functions
*/

#include <iostream>

using namespace std;

//  output all the elements of the array in one rows
void printArray( int A[], int n ){
    for( int i = 0; i < n; i++ ){
        cout << A[i] << " ";
    }
    cout << endl;
}

// bool equal(int* a, int* b){
//     return equal(*a, *b);
// }

bool equal(int& a, int& b){
    return a && b;
}

int main(){

    int a = 1, b = 0;

    cout << equal(a, b) << endl;
}

