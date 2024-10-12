/* Jeffrey Interiano
CS 2000
Instructor: Dakota Hernandez
*/

#include <iostream>
// ToDo: Add include files.
#include <algorithm>
#include <cctype>
#include <locale>
#include <string>
#include <vector>

using namespace std;

string removePunct(string str);
// Function: removePunct
// Precondition: a string that may or may not have punctuation.
// Postcondition: returns a (possibly shorter) string with punctuaton
// removed.

string convertToLower(string str);
// Precondition: a string that may have mixed case in it.
// Postcondition: returns a lowercase string

string reverse(string str);
// Precondition: a string to be reversed
// Postcondition: returns a string that is the
// reverse of the input string.

void display(vector<string> vstrings);
// Precondition: a vector of strings to print
// Postcondition: strings are printed one per line.

bool isPalindrome(string str);
// Precondition: a string to be tested
// Postcondition: returns a bool that is true if the input is a palindrome
// returns false otherwise.

int main() {

   // ToDo: Declare two vectors of strings to save the input strings: palindromes,
   // not_palindromes.
    vector<string> palindromes;
    vector<string> notPalindromes;

   // ToDo: Implement a loop to read in the palindrome strings using getline until
   // the user quits. The user will enter the word "quit" to exit the loop.
   string input;
    while (true) {
        cout << "Enter your palindrome or type quit:" << endl;
        getline(cin, input);

        if (input == "quit") {
            break;
        }

   // ToDo: In the loop, call the isPalindrome function on the input string and
   // store it in the palindromes vector if true and the notPalindromes vector if
   // false.
   string cleanInput = convertToLower(removePunct(input));
        if (isPalindrome(cleanInput)) {
            palindromes.push_back(input);
        } else {
            notPalindromes.push_back(input);
        }
    }

   // ToDo: After exiting the loop, print the list of palindromes under a Palindrome
   // heading and the list that are not palindromes under a Not Palindrome heading.
   // The display function should print a tab character before printing the string.
   cout << "Palindrome:" << endl;
    display(palindromes);

    cout << "Not Palindrome:" << endl;
    display(notPalindromes);

	return 0;
}

string removePunct(string str) {
    str.erase(remove_if(str.begin(), str.end(), [](char c) { return !isalnum(c); }), str.end());
    return str;
}

string convertToLower(string str) {
    locale loc;
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i], loc);
    }
    return str;
}

string reverse(string str) {
    int i = 0, j = str.length() - 1;
    while (i < j) {
        swap(str[i], str[j]);
        i++;
        j--;
    }
    return str;
}


void display(vector<string> vstrings) {
    for (string str : vstrings) {
        cout << "\t" << str << endl;
    }
}

bool isPalindrome(string str) {
    string reversed = reverse(str);
    return str == reversed;
}