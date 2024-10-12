// Jeffrey Interiano
// CS 2000
// MidtermB

#include <iostream>
using namespace std;

// Find the number of values stored that is less than 0 and the number greater than
// 0 in a partially filled array of int, which uses the special sentinel value 0 to 
// indicate the end of the array
// @param a: int array 
// @param less: number of values less than 0
// @param greater: number of values greater than 0
void findLessAndGreater(int a[], int& less, int& greater)
{
    // start program all at 0
    less = 0;
    greater = 0;
    int i = 0;

    while(a[i] != 0) { // while i is not equal to 0
        if(a[i] < 0) { // if i is less than 0
            less++; // count less
        } else if(a[i] > 0) { // if else read when numbers are greater than 0
            greater++; // count greater
        }
        i++;
    }
}

int main()
{
    int a[] = { -15, 23, 32, -12, 10, 9, -43, 5, -999, 0 }; // when reaching 0 program ends
    int less, greater;

    findLessAndGreater(a, less, greater); // call function

    // Print the results
    cout << "Number of values less than 0 is " << less << endl; // output values less than 0
    cout << "Number of values greater than 0 is " << greater << endl; // output values greater than 0
    return 0;
}
