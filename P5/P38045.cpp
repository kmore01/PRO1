// program that calculates square and the square root of sequence of natural numbers

#include <iostream>
#include <cmath>
using namespace std;

// function that calculates square
// Precondition: natural
// Postcondition: natural
int square(int number) {
    return number * number;
}

// function that calculates square root
// Precondition: natural
// Postcondition: double
double square_root(int number) {
    return sqrt(number);
}

int main () {
    int number; // sequence of natural numbers
    while (cin >> number) {
        cout.setf(ios::fixed);
        cout.precision(6); 
        cout << square(number) << ' ' << square_root(number) << endl;
    }
}