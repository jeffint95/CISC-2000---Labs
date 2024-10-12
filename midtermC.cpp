// Jeffrey Interiano
// CS 2000
// MidtermC

#include <string>
#include <iostream>
using namespace std;

int countVowels(string word);

int main()
{ 
  string phrase;
  cout << "Enter a phrase: ";
  // To do: implement user input
  getline(cin, phrase);
  
  cout << "Number of vowels: " << countVowels(phrase) << endl;
}
    
// To do: Implement countVowels 
int countVowels(string word)
{
    int count = 0;
    int length = word.length();

    for(int i = 0; i < length; i++) {
      if (
        word[i] == 'a' || word[i] == 'A' ||
        word[i] == 'e' || word[i] == 'E' ||
        word[i] == 'i' || word[i] == 'I' ||
        word[i] == 'o' || word[i] == 'O' ||
        word[i] == 'u' || word[i] == 'U' ||
        word[i] == 'y' || word[i] == 'Y') {
        count++;
      }
    }

    return count;
}