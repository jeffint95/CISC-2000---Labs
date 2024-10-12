// Jeffrey Interiano
// CISC 2000
// Instructor: Dakota Hernandez
// Teacher Assistant: Pavel Vasilyev
// InflationRate Part 3

#include <iostream>
using namespace std;

void getCPIValues(double& oldCpi, double& newCpi)
{
    do
    {
        cout << "Enter the old and new consumer price indices: ";

        cin >> oldCpi; 
        cin >> newCpi;

        if (oldCpi <= 0 || newCpi <=0)
        {
            cout << "Error: CPI values must be greater than 0 " << endl;
        }
        
    } 
    while (oldCpi <= 0 || newCpi <= 0);

}

// declare a bubble sort to sort user's input
void bubbleSort(double array[], int length)
{
    int i, j;
    
    for(i = 0; i < length - 1; i++)
    {
        for(j = 0; j < length - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                // Swap element at [j] with element at  [j+1]
                double temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

void printAverage(double array[], int length)
{
    int i;
    double sum = 0;

    for(i = 0; i < length; i++)
    {
        sum += array[i];
    }
    
    cout << "Average rate is " << (sum / length) << endl;
}

// find the median of the array by diving the sum of the array by the number of arrays
double printMedian(double arr[], int size)
{
   
    bubbleSort(arr, size);

   if (size % 2 !=0) 
   {
    // size is an odd number
    return (double)arr[size/2];
   }

    // size is an even number
   return (double)(arr[(size-1)/2] + arr[size/2])/2.0;
}


int main()
{

    // declare doubles
    double oldCpi;
    double newCpi;
    double inflationRate;

    int positionOfCurrentRate = 0;
    int noOfRatesCalculated = 0; // How many rates we've calculated
    int MAX_RATES = 20; // Maximum number of rates we can calculate
    double rates[MAX_RATES]; // Array that holds all the rates we've calculated

    double arr[noOfRatesCalculated]; //we are using the number of rates calculated
    double size = sizeof(arr)/sizeof(arr[0]); 
    
    //create infinite while loop 
    while(1)
    {
        // call getCPIValues
        getCPIValues(oldCpi, newCpi);

        //wont allow a negative output
        if(oldCpi > 0 && newCpi > 0)
        {
            inflationRate = (newCpi - oldCpi) / oldCpi * 100;
        }

        else
        {
            inflationRate = 0;
        }

        cout << "Inflation rate is " << inflationRate << endl;

         if (inflationRate != 0) {
            rates[positionOfCurrentRate] = inflationRate;
            positionOfCurrentRate++;
    
            noOfRatesCalculated++; 
    
            if (noOfRatesCalculated == MAX_RATES)
                break;
        }

        char a;
        cout << "Try again? (y or Y): ";
        cin >> a;

        //stopping input from user from loop
        if(a == 'n' || a == 'N')
            break;
    }
     
    // Print average
    printAverage(rates, noOfRatesCalculated);
    
    //utilize the max rates and noRatesCalculated
    cout << "Median rate is " << printMedian(rates, noOfRatesCalculated) << endl;

    return 0;

}