// Jeffrey Interiano
// CS 2000
// MidtermA

#include <iostream>
using namespace std;

// Function to swap two ints using pointers
// @param pointer to an int
// @param pointer to an int
void swap(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2; // pointer 1 is equal to that of pointer 2
    *ptr2 = temp; // pointer 2 is filled with temp memory
}

// Function to reverse array
void reverse(int a[], int size)
{
    for (int i = 0; i < size / 2; i++) {
        swap(&a[i], &a[size-i-1]); // call swap function
    }
}

int main()
{
    int size = 5;
    int* a = new int[size]; // allocate memory for array
    for (int i = 0; i < size; i++) {
        a[i] = i + 1; // fill array with elements 1-5
    }
    reverse(a, size); // call reverse function
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    delete[] a; // free memory
    return 0;
}
