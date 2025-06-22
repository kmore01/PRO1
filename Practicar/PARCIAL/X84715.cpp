// programa que escriu la forma de la lletra 'V' en base a la altura

#include <iostream>
using namespace std;

int main () {
    int altura; // enter > 0
    cin >> altura;
    for (int i = 0; i < altura; ++i) { // columnas
        for (int j = i; j > 0; --j) { // espais inicials
            cout << ' ';
        }
        cout << 'V';
        for (int j = (2 * (altura - i)) - 3; j > 0; --j) { // espais intermitjos
            cout << ' ';
        }
        if ((i + 1) != altura) cout << 'V';
        cout << endl;
    }
}