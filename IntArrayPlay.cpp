/* Working with arrays and functions
 * Author: Jeffrey Interiano
 * CISC 2000
 */

#include <algorithm>
#include <iostream>

using namespace std;

const int CAPACITY = 20;

// functions
void displayArray(int array[], int numElements);
void fillArray(int array[], int& numElements);
bool isArraySorted(int array[], int numElements);
int findPosition(int array[], int numElements, int insertval);
int searchElement(int array[], int numElements, int element);
bool removeElement(int array[], int& numElements, int positionElement);
bool insertElement(int array[], int& numElements, int positionElement, int target);

// displayArray -  display the array on a single line separated by blanks.
// @param: int array[] is an array of integers
// @param: int numberOfElements
void displayArray(int array[], int numElements) {
  for (int i = 0; i < numElements; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

// ToDo: Declare a function fillArray that fills an int array with values
// entered by the user. Stop reading when the user inputs -1 or you reach
// CAPACITY.
//  fillArray - read a list of positive integers ending with -1 or until
//  CAPACITY
//  @param: int array[] is an array of integers when leaving this function
//  @param: int& numElements is the number of Elements in the array when done
//  @returns void.
void fillArray(int array[], int& numElements) {
  for (int i = 0; i < CAPACITY; i++) {
    cin >> array[i];
    numElements++;
    if (array[i] == (-1)) {
      numElements--;
      break;
    }
  }
}

// ToDo: Declare a function isArraySorted that determines if an array is in
// order
//  isArraySorted - goes thru the elements checking to see if they are in order
//  @param: int array[] is an array
//  @param: int numElements
//  @returns: true if the array is in sorted order, false otherwise
bool isArraySorted(int array[], int numElements) {
  for (int i = 0; i < numElements - 1; i++) {
    if ((array[i] > (array[i + 1]))) {
      cout << "Array is not sorted" << endl;
      return false;
    }
  }
  cout << "Array is sorted" << endl;
  return true;
}

// ToDo: Declare a function that finds the insert position for a given value
// in an ordered array.
//  findPosition - looks thru an ordered array to find the position of
//  the value to insert. All values before are less than the target value.
//  Value after should be greater than the target value. [No need to sort]
//  @param: int array[] is an ordered array
//  @param: int numElements
//  @param: int value to insert
//  @return index of the position where the element should be inserted
int findPosition(int array[], int numElements, int insertval) {
  for (int i = 0; i < numElements; i++) {
    if (array[i] > insertval) {
      return i;
    }
  }
  return numElements;
}

// ToDo: Declare a funcxtion that searches for an element in the given array
//  searchElement - searches for the element in the given array.
//  @param int array[] is an unordered array of integers
//  @param int numberOfElements
//  @param int element
//  @returns index of element or -1 if not found.
int searchElement(int array[], int numElements, int element) {
  int index;
  for (int i = 0; i < numElements; i++) {
    if (array[i] == element) {
      index = i;
      ;
      break;
    } else if (array[i] != element) {
      index = -1;
    }
  }
  return index;
}

// ToDo: Declare a function that removes (i.e., deletes) the element
//  removeElement - removes the element of the given index from the given array.
//  @param: int array[] is an unordered array of integers
//  @param: int&amp; numberElements
//  @param: int position of element to delete
//  @returns: true if delete was successful, false otherwise
bool removeElement(int array[], int& numElements, int positionElement) {
  if (positionElement == -1) {
    cout << "Error: position out of range: -1 " << endl;
    return false;
  } else {
    for (int i = 0; i < numElements; i++) {
      if (i == positionElement) {
        for (int j = positionElement; j < numElements; j++) {
          array[j] = array[j + 1];
        }
        numElements = numElements - 1;
      }
    }
    for (int i = 0; i < numElements; i++) {
      if (array[i] == array[positionElement]) {
        return false;
      }
    }
  }
  return true;
}

// ToDo: Delcare a function that inserts the target element in the given
// position
//  insertElement - removes the element of the given index from the given array.
//  @param: int array[] is an ordered array of integers
//  @param: int &numElements
//  @param: int position to insert into
//  @param: int target to insert.
//  @returns: true if insert was successful, false otherwise
bool insertElement(int array[], int& numElements, int positionElement, int target) {
  if (numElements > CAPACITY - 1) {
    cout << "Error: array is full" << endl;
    return false;
  }
  for (int j = numElements; j >= positionElement; j--) {
    array[j + 1] = array[j];
  }
  array[positionElement] = target;
  numElements++;

  for (int i = 0; i < numElements; i++) {
    if (array[i] == array[positionElement]) {
      return true;
    }
  }
  return false;
}

int main() {
  // The numArray can be partially filled, we use the variable numArrayElems
  // to keep track of how many numbers have been stored in the array.
  int numArray[CAPACITY];  // an int array with a given CAPACITY
  int numArrayElems = 0;   // the array is initially empty, i.e., contains 0 elements

  // 1. ToDo: Call your fillArray function to read in a sequence of integer
  // values, separated by space, and ending with -1. Store the values in the
  // numArray array and the number of elements in numArrayElems. Display the
  // content of the array afterwards
  cout << "Enter a list of up to 20 integers or -1 to end the list" << endl;
  fillArray(numArray, numArrayElems);
  displayArray(numArray, numArrayElems);

  // 2. ToDo: Read in a value from the user. Call your findPosition function
  // to get the position to insert, then call insertElement to insert the value
  // into the position of the array.
  // Display the contents of the array afterwards
  cout << "Enter a value to insert: ";
  int usersValue;
  cin >> usersValue;
  int insertPosition = findPosition(numArray, numArrayElems, usersValue);
  insertElement(numArray, numArrayElems, insertPosition, usersValue);
  displayArray(numArray, numArrayElems);

  // 3. ToDo: Use your isArraySorted function to tell whether the array is
  // sorted.
  isArraySorted(numArray, numArrayElems);

  // 4. ToDo: Read in a value from the user. Call your searchElement function
  // to get the position to remove, then call removeElement to delete it.
  // a value to the end of the array
  // Display the content of the array afterwards
  cout << "Enter a value to remove: ";
  int removeValue;
  cin >> removeValue;
  int removePosition = searchElement(numArray, numArrayElems, removeValue);
  removeElement(numArray, numArrayElems, removePosition);
  displayArray(numArray, numArrayElems);

  return 0;
}

// TODO: Implement all functions declared above.
// Don't forget to put precondition/postcondition comments under or over the function header.
