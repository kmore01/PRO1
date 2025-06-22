// programa que escriu la representació binària del revés d'un nombre

#include <iostream>
using namespace std;

int main () {
    int numero;
    cin >> numero;
    if (numero == 0) {
        cout << numero << endl;
    }
    int binarioreves;
    while (numero >= 1) {
        binarioreves = numero % 2;
        numero = numero / 2; 
        cout << binarioreves;
        if (numero == 0) {
            cout << endl;
        }
    }
}