// Jeffrey Interiano
// CISC 2000
// Instructor: Dakota Hernandez

#include <iostream>
using namespace std;

/* A function that reads a sequence of integers from input to fill a dynamically allocated array. For example, if the length is 3, and the numbers are 123 345 99 then the array returned will be of size 3, and stores values 123, 345 and 99.
@param size: upon return, stores the size of the array
@return the pointer pointing to the array
*/
int * ReadNumberSequence(int & length)
{
	int * array = NULL; // initialize the pointer to NULL
	do {
		cout << "Enter the length of the number sequence: ";
		cin >> length; 
	} while (length <= 0);
	// Todo: Write a statement to allocate memory for the array.
    array = new int[length];

	// Note: we know the value of size only at run time, so we need to DYNAMICALLY
	// Todo: write a loop to read size # of int from input, and store in the array
    cout << "Enter " << (length) << " number of elements to store in the array: ";   
    for(int i=0; i < length; i++)
    {
        cin >> array[i];
    }
    
	return array;
}
int main()
{
	// Todo: delcare necesssary variables
    int *k;
    int length;

	// Todo: call the ReadNumberSequence function to read a sequence of numbers
    k = ReadNumberSequence(length);

	// Todo: write a loop to display the elements in the array returned ...
    for(int i = 0; i < length; i++)
    {
        cout << k[i] << " " << endl;
    }


	// Todo: free the array returned by ReadNumberSequence.
    delete[]k;


	return 0;
}