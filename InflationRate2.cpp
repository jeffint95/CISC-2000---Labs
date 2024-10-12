#include <iostream>
using namespace std;

// part one
int main()
{

    // declare floats
    float oldCpi;
    float newCpi;
    float res;
    int value = 0;
    float inflationRate;

    // create infinite while loop
    while (1)
    {
        cout << "Enter the old and new consumer price indices: ";

        cin >> oldCpi;
        cin >> newCpi;

        // wont allow a negative output
        if (oldCpi > 0 && newCpi > 0)
        {
            inflationRate = (newCpi - oldCpi) / oldCpi * 100;
        }

        else
        {
            inflationRate = 0;
        }

        cout << "Inflation rate is " << inflationRate << endl;

        // part two (average)

        // average portion of code
        if (inflationRate != 0)
        {
            value = value + 1;
            res = res + inflationRate;
        }

        char a;
        cout << "Try again? (y or Y): ";
        cin >> a;

        // stopping input from user from loop
        if (a == 'n' || a == 'N')
            break;
    }

    // result of average
    cout << "Average rate is " << res / value;

    return 0;
}