// program that calculates the simple altenated sum 1−2+3−4+…+ (−1)^n+1 · n

#include <iostream>
using namespace std;

// function that returns the simple alternated sum
// Precondition: n >= 1
// Postcondition: Returns 1-2+3-4+...+(-1)^(n+1)*n
int simpleAlternatedSum(int n) {
    if (n < 2) return 1; // base case
    else { // general case
        if (n % 2 != 0) return n + simpleAlternatedSum(n - 1); // odd numbers
        else return simpleAlternatedSum(n - 1) - n; // even numbers
    }
}

int main () {
    int number;
    while (cin >> number) cout << simpleAlternatedSum(number) << endl;
}