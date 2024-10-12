#include <iostream>
using namespace std;

//part one

int main()
{
    float oldCpi;
    float newCpi;
    float res;
    int value = 0;
    float inflationRate;
    
    {
        cout << "Enter the old and new consumer price indices: ";

        cin >> oldCpi; 
        cin >> newCpi;

        if(oldCpi > 0 && newCpi >= 0)
        {
            inflationRate = (newCpi - oldCpi) / oldCpi * 100;
        }

        else
        {
            inflationRate = 0;
        }

        cout << "Inflation rate is " << inflationRate << endl;
    }
}