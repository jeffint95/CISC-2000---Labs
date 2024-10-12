/* Jeffrey Interiano
Instructor: Dakota Hernandez
CISC 2000
 */

#include <iostream>

using namespace std;

// Type definition
typedef int* IntPtr;

// Constants
const int NUMLABS = 4;

// Function prototypes

/*
 Creates the dynamic arrays for the labs.
 @param labs: the array of labs,
 @param labsizes: contains the size (or number of computers) of each lab
  This dictates the size of the dynamic array.
 @precondition: labsize[0] is the # of computers in lab1,
                labsize[1] is the # of computers in lab2, ...
 @postcondition: labs[0] points to lab1's array (of size given by labsize[0])
      labs[1] points to lab2's array (of size given by labsize[1])
        ...
*/
void createArrays(IntPtr labs[], int labsizes[]);

/*
freeArrays:
Releases memory we allocated with "new".
*/
void freeArrays(IntPtr labs[]);

/*
showLabs:
Displays the status of all labs (who is logged into which computer).
*/
void showLabs(IntPtr labs[], int labsizes[]);

// ======================
// login:
// Simulates a user login by asking for the login info from
// the console.
// ======================
void login(IntPtr labs[], int labsizes[]);

// ======================
// logout:
// Searches through the arrays for the input user ID and if found
// logs that user out.
// ======================
void logout(IntPtr labs[], int labsizes[]);

// ======================
// search:
// Searches through the arrays for the input user ID and if found
// outputs the station number.
// ======================
void search(IntPtr labs[], int labsizes[]);

// ======================
//     main function
// ======================
int main() {
  IntPtr labs[NUMLABS];   // store the pointers to the dynamic array for each lab
  int labsizes[NUMLABS];  // Number of computers in each lab
  int choice = -1;

  cout << "Welcome to the LabMonitorProgram!\n";

  // Prompt the user to enter labsizes
  cout << "Please enter the number of computer stations in each lab:\n";
  for (int i = 0; i < NUMLABS; i++) {
    do {
      cout << "How many computers in Lab " << i + 1 << "?";
      cin >> labsizes[i];
    } while (labsizes[i] < 0);
  }

  // Create ragged array structure
  createArrays(labs, labsizes);

  // Main Menu
  while (choice != 0) {
    cout << endl;
    cout << "MAIN MENU" << endl;
    cout << "0) Quit" << endl;
    cout << "1) Simulate login" << endl;
    cout << "2) Simulate logout" << endl;
    cout << "3) Search" << endl;
    cin >> choice;
    if (choice == 1) {
      login(labs, labsizes);
      showLabs(labs, labsizes);
    } else if (choice == 2) {
      logout(labs, labsizes);
      showLabs(labs, labsizes);
    } else if (choice == 3) {
      search(labs, labsizes);
    }
  }
  freeArrays(labs);  // Free memory before exiting
  cout << "Bye!\n";
  return 0;
}

void createArrays(IntPtr labs[], int labsizes[]) {
  // Implement the Code!
  // Hint: for each of the 4 labs, dynamically allocate an int array of size given by the number of computers in the lab.
  for (int i = 0; i < NUMLABS; i++) {
    labs[i] = new int(labsizes[i]);
    for (int j = 0; j < labsizes[i]; j++) {
      labs[i][j] = -1;
    }
  }
}

void freeArrays(IntPtr labs[]) {
  for (int i = 0; i < NUMLABS; i++) {
    delete labs[i];
  }
}

/* showLabs:
   Displays the status of all labs (who is logged into which computer).
   Precondition: labs[] is a multidimension array of labs with computers
                 labsizes[i] contains the size of the array in labs[i]

 */
void showLabs(IntPtr labs[], int labsizes[]) {
  int i;
  int j;

  cout << "LAB STATUS" << endl;
  cout << "Lab # Computer Stations" << endl;
  for (i = 0; i < NUMLABS; i++) {
    cout << i + 1 << " ";
    for (j = 0; j < labsizes[i]; j++) {
      cout << (j + 1) << ": ";
      if (labs[i][j] == -1) {
        cout << "empty ";
      } else {
        cout << labs[i][j] << " ";
      }
    }
    cout << endl;
  }
  cout << endl;
  return;
}

void login(IntPtr labs[], int labsizes[]) {
  int id, lab, num = -1;

  do {
    cout << "Enter the 5 digit ID number of the user logging in:" << endl;
    cin >> id;
  } while ((id < 10000) || (id > 99999));

  do {
    cout << "Enter the lab number the user is logging in from (1-" << NUMLABS << "):" << endl;
    cin >> lab;
  } while ((lab <= 0) || (lab > NUMLABS));

  do {
    cout << "Enter computer station number the user is logging in to "
         << "(1-" << labsizes[lab - 1] << "):" << endl;
    cin >> num;
  } while ((num <= 0) || (num > labsizes[lab - 1]));

  if (labs[lab - 1][num - 1] != -1) {
    cout << "ERROR, user " << labs[lab - 1][num - 1] << " is already logged into that station." << endl;
    return;
  }
  labs[lab - 1][num - 1] = id;
  return;
}

void logout(IntPtr labs[], int labsizes[]) {
  int id;
  int posI = -1, posJ = -1;
  do {
    cout << "Enter the 5 digit ID number of the user logging in:" << endl;
    cin >> id;
  } while ((id < 10000) || (id > 99999));
  for (int i = 0; i < NUMLABS; i++) {
    for (int j = 0; j < labsizes[i]; j++) {
      if (labs[i][j] == id) {
        labs[i][j] = -1;
        posI = i;
        posJ = j;
      }
    }
  }
  if (posI >= 0 && posJ >= 0) {
    cout << "Logout user ";
    cout << id;
    cout << " in Lab ";
    cout << posI + 1;
    cout << " at computer ";
    cout << posJ + 1 << endl;
  } else {
    cout << "User not logged in." << endl;
  }
}

void search(IntPtr labs[], int labsizes[]) {
  int id;
  int posI = -1, posJ = -1;
  do {
    cout << "Enter the 5 digit ID number of the user logging in:" << endl;
    cin >> id;
  } while ((id < 10000) || (id > 99999));
  for (int i = 0; i < NUMLABS; i++) {
    for (int j = 0; j < labsizes[i]; j++) {
      if (labs[i][j] == id) {
        posI = i;
        posJ = j;
      }
    }
  }
  if (posI >= 0 && posJ >= 0) {
    cout << "User ";
    cout << id;
    cout << " logged in Lab ";
    cout << posI + 1;
    cout << " at computer ";
    cout << posJ + 1 << endl;
  } else {
    cout << "User not logged in." << endl;
  }
}