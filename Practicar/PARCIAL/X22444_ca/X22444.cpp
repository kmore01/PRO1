// programa que diu si un numero es impar-par
// impar-par es aquell numero que la suma de les seves xifres senars és parell

#include <iostream>
using namespace std;

int main () {
    int numero; // sequencia d'enters no negatius
    bool found = false;
    int numero_guardat = 0;
    while (not found and cin >> numero) {
        int suma_senars = 0;
        numero_guardat = numero;
        while (numero > 0) { // sumes els numeros senars
            if ((numero % 10) % 2 != 0) suma_senars = suma_senars + (numero % 10);
            numero /= 10;
        }
        if (suma_senars % 2 == 0) found = true;
    }
    if (found) cout << numero_guardat << endl;
    else cout << "no impar-par" << endl;
}