// program that reads a natural number n, and prints 2n âˆ’ 1 bars of asterisks

#include <iostream>
using namespace std;

// function that prints asterisks of the bar
void bars (int size) {
    if (size != 0) {
        cout << '*';
        bars(size - 1);
    }
}

// function that prints bars according to the size
void romb (int size) {
    if (size != 0) {
        romb(size - 1); // first part
        bars(size); // line
        cout << endl;
        romb(size - 1); // second part
    }
}

int main () {
    int size; // natural > 0
    cin >> size;
    romb(size);
}