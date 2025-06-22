// program that print if first fraction is smaller than the other

#include <iostream>
using namespace std;

// function that determinates if first fraction is smaller than second
// Precondition: denominators > 0
// Postcondition: bool
bool c_frac(int n1, int d1, int n2, int d2) {
    return (double(n1)/double(d1) < double(n2)/double(d2));
}

int main () {
    int n1, d1, n2, d2; // integers
    cin >> n1 >> d1 >> n2 >> d2;
    if (c_frac(n1, d1, n2, d2)) cout << "yes" << endl;
    else cout << "no" << endl;
}