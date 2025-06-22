// program that calculates the number of digits

#include <iostream>
using namespace std;

// function that returns the number of digits
// Precondition: n ≥ 0
// Postcondition: natural
int number_of_digits(int n) {
    if (n / 10 > 0) return 1 + number_of_digits(n / 10); // general case
    else return 1; // base case
}

int main () {
    int num; // natural
    cin >> num;
    cout << number_of_digits(num) << endl;
}