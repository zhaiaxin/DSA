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
