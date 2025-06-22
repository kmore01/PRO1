// program that calculates if a natural number n is increasing

#include <iostream>
using namespace std;

// function that calculates if a number is increasing
// Precondition: no
//  Postcondition: no
bool is_increasing(int n) {
    if (n >= 100) { // general case
        return n % 10 >= (n / 10) % 10 and is_increasing(n / 10);
    }
    else return n % 10 >= n / 10; // base case
}

int main () {
    int number;
    while (cin >> number) {
        if (is_increasing(number)) cout << "true" << endl;
        else cout << "false" << endl;
    }
}