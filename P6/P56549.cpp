// program that calculates natural numbers in binary, octal and hexadecimal

#include <iostream>
using namespace std;

// function that calculates binary of a number
void binary_notation(int& binary, int number) {
    if (number > 0) {
        binary_notation(binary, number / 2);
        cout << number % 2;
    }
}

// function that calculates octal of a number
void octal_notation(int& octal, int number) {
    if (number > 0) {
        octal_notation(octal, number / 8);
        cout << number % 8;
    }
}
// function that calculates hexadecimal of a number
void hexa_notation(int& hexa, int number) {
    if (number > 0) {
        hexa_notation(hexa, number / 16);
        if (number % 16 <= 9) cout << number % 16;
        else {
            if (number % 16 == 10) cout << "A";
            else if (number % 16 == 11) cout << "B";
            else if (number % 16 == 12) cout << "C";
            else if (number % 16 == 13) cout << "D";
            else if (number % 16 == 14) cout << "E";
            else cout << "F";
        }
    }
}

int main () {
    int binary = 0, octal = 0, hexa = 0, number;
    while (cin >> number) {
        cout << number << " = ";
        if (number != 0) {
            binary_notation(binary, number);
            cout << ", ";
            octal_notation(octal, number);
            cout << ", ";
            hexa_notation(hexa, number);
            cout << endl;
        }
        else cout << binary << ", " << octal << ", " << hexa << endl;
    }
}