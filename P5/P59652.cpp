// programa que llegeix un numerador/denominador i dona la versio reduida

#include <iostream>
using namespace std;

// funcio que fa el MCD de dos enters
// Precondicion: dos enters
// Postcondicion: dos enters
int MCD(int num, int den) { 
    while (den != 0) {
        int r = num % den;
        num = den;
        den = r;
    }
    return num; // aquest es el MCD
}

// funcio que llegeix un racional amb la forma num/den i dona la versio reduida
// Precondicion: 1 ≤ num ≤ 10^9 i 1 ≤ den ≤ 10^9
// Postcondicion: dos enters
void read_rational(int& num, int& den) {
    char barra;
    cin >> num >> barra >> den;
    int divisor = MCD(num, den);
    num /= divisor;
    den /= divisor;
}

int main () {
    int num, den;
    read_rational(num, den);
    cout << num << '/' << den << endl;
}