// programa que escriu la representació hexadecimal del revés d'un nombre

#include <iostream>
using namespace std;

int main () {
    int decimal;
    cin >> decimal;
    if (decimal == 0) {
        cout << decimal << endl;
    }
    int hexadecimal;
    while (decimal >= 1) {
        hexadecimal = decimal % 16;
        decimal = decimal / 16;

        if (hexadecimal <= 9)  cout << hexadecimal;
        else if (hexadecimal == 10) cout << 'A';
        else if (hexadecimal == 11) cout << 'B';
        else if (hexadecimal == 12) cout << 'C';
        else if (hexadecimal == 13) cout << 'D';
        else if (hexadecimal == 14) cout << 'E';
        else if (hexadecimal == 15) cout << 'F';
        if (decimal == 0) {
            cout << endl;
        }
    }
}