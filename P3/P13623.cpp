// programa que donat un tauler calcula el nombre total de monedes contingudes a les caselles blanques

#include <iostream>
using namespace std;

int main () {
    int files, columnes;
    cin >> files >> columnes;
    int suma = 0;
    for (int i = 0; i < files; ++i) { // files
        for (int j = 0; j < columnes; ++j) { // columnes
            char monedas; // caràcter
            cin >> monedas;
            if ((i + j) % 2 == 0) { // suma de la fila i columna parells
                suma += monedas - '0'; // convertir monedas a entero
            }
        }
    }
    cout << suma << endl;
}