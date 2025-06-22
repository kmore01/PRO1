// program that calculates factorial

#include <iostream>
using namespace std;

// function that returns factorial
// Precondition: 0 ≤ n ≤ 12
// Postcondition: natural > 0
int factorial(int n) {
    if (n > 0) return n * factorial(n - 1); // general case
    else return 1; // base case
}

int main () {
    int num; // 0 ≤ num ≤ 12
    cin >> num;
    cout << factorial(num) << endl;
}