// program that prints if a natural number is a perfect number
// a perfect number is equal to the sum of all its divisors except itself

#include <iostream>
#include <cmath>
using namespace std;

// function that calculates if a natural is a perfect number
// Precondition: natural
// Postcondition: bool
bool is_perfect(int n) {
    int sum = 0;
    for (int i = 1; i < sqrt(n); ++i) {
        if (n % i == 0) sum += i + (n / i);
    }
    if (n != 0) return sum == 2 * n;
    else return false;
}

int main () {
    int num; // natural
    cin >> num;
    if (is_perfect(num)) cout << "true" << endl;
    else cout << "false" << endl;
}