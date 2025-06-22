// programa que a partir d'un tauler compta les monedas totals que hi ha

#include <iostream>
using namespace std;

int main () {
    int files, columnes; // naturals ≥ 1
    cin >> files >> columnes;
    int suma = 0;
    for (int i = 0; i < files; ++i) { // files
        for (int j = 0; j < columnes; ++j) { // columnes
            char monedas; // caràcter
            cin >> monedas;
            suma += monedas - '0'; // convertir monedas a enter
        }
    }
    cout << suma << endl;
}