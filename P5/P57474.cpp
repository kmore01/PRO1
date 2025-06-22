// program that calculates the factorial of a number

#include <iostream>
using namespace std;

// function that calculates the factorial
// Precondition: 0 ≤ integer ≤ 12
// Postcondition: integer
int factorial(int n) {
    int answer = n;
    for (int i = 1; i < n; ++i) {
        answer *= i;
    }
    if (answer == 0) ++answer;
    return answer;
}

int main () {
    int number; // 0 ≤ integer ≤ 12
    cin >> number;
    cout << factorial(number) << endl;
}