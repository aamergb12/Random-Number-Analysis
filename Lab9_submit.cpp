/*
Aamer Goual-Belhamidi
axg210204
Programming Fundamentals
CS1436.008
11/30/23
11/17/23
11/30/23
*/

//Number Analysis Program

#include <iostream>
#include <cstdlib>
#include <ctime>

#include <iomanip>
//making sure average is to 2 decimals

using namespace std;

const int MAX_SIZE = 5000;
const int MIN_SIZE = 4000;
const int MAX_POP = 100000;
const int MIN_POP = 1000;
//global constants because each function uses it

void generateRandomArray(int array[], int size);
int getTotalCount(int array[], int size);
int getHighestValue(int array[], int size);
int getLowestValue(int array[], int size);
int getSum(int array[], int size);
double getAverage(int sum, int count);
//function prototypes, each listed with function use

int main() {
    unsigned seed = time(0);
    srand(seed);
    //randomization framework

    int sizeOfArray = rand() % (MAX_SIZE - MIN_SIZE + 1) + MIN_SIZE;
    int mainArray[sizeOfArray];
    //using randomization to create the size of the array
    //also declaring the array

    generateRandomArray(mainArray, sizeOfArray);
    //populating the array^^

    int totalCount = getTotalCount(mainArray, sizeOfArray);
    cout << "The total count of numbers in the array is: " << totalCount << endl;
//could just use sizeOfArray but created Func to calculate

    int highestValue = getHighestValue(mainArray, sizeOfArray);
    cout << "The highest value in the array is: " << highestValue << endl;
    //class framework

    int lowestValue = getLowestValue(mainArray, sizeOfArray);
    cout << "The lowest value in the array is: " << lowestValue << endl;
//same as high

    int sum = getSum(mainArray, sizeOfArray);
    cout << "The sum of all the elements in the array is: " << sum << endl;
//function call

    double average = getAverage(sum, totalCount);
    cout << "The average of the numbers in the array is: ";
    cout << fixed << setprecision(2) << average << endl;
    //calling average func to get average of array list
    //using setprecision to make to set to a max of 2 decimal points

    //having each function call represent a variable so user readability is better

    return 0;
}

void generateRandomArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % (MAX_POP - MIN_POP + 1) + MIN_POP;
//for loop used to populate the array
    }
}

int getTotalCount(int array[], int size) {
    return size;
//uses size given in argument to return to the main
}

int getHighestValue(int array[], int size) {
    int high = array[0];
    for (int j = 1; j < size; j++) {
        if (array[j] > high)
            high = array[j];
//highest val calculator framework from class notes
    }
    return high;
}

int getLowestValue(int array[], int size) {
    int low = array[0];
    for (int k = 1; k < size; k++) {
        if (array[k] < low)
            low = array[k];
//same for high but flipped
    }
    return low;
}

int getSum(int array[], int size) {
    int sum = 0;
    for (int l = 0; l < size; l++) {
        sum += array[l];
    }
    return sum;
//using for loop to add up all the elements in the array
}

double getAverage(int sum, int count) {
    return static_cast<double>(sum) / count;
//uses previously declared integers from the main to get the avg
}
