// program that calculates sine and cosine of natural numbers

#include <iostream>
#include <cmath>
using namespace std;

// function that calculates sine
// Precondition: double in radians
// Postcondition: double
double sine(double angle) {
    return sin(angle);
}

// function that calculates cosine
// Precondition: double in radians
// Postcondition: double
double cosine(double angle) {
    return cos(angle);
}

int main () {
    double angle; // real number in degrees
    while (cin >> angle) {
        angle *= (M_PI / 180);
        cout.setf(ios::fixed);
        cout.precision(6); 
        cout << sine(angle) << ' ' << cosine(angle) << endl;
    }
}