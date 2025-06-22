// program that returns the sum of digits

#include <iostream>
using namespace std;

// function that sum digits
// Precondition: natural
// Postcondition: natural 
int sum_of_digits(int x) {
    if (x > 9) return x % 10 + sum_of_digits(x / 10);
    else return x;
}

// function that reduce digits
// Precondition: natural
// Postcondition: natural 
int reduction_of_digits(int x) {
    if (sum_of_digits(x) >= 10) return reduction_of_digits(sum_of_digits(x)); 
    // la función se llama a sí misma de manera recursiva con la suma como
    // argumento hasta obtener una suma de un solo dígito
    else return sum_of_digits(x);
}

int main () {
    int num;
    cin >> num;
    cout << reduction_of_digits(num) << endl;
}