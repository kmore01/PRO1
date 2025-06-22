// programa que diu el primer complementari a un numero
// complementari es aquell que (n + m) % 10 = 0

#include <iostream>
using namespace std;

int main () {
    int numero, sequencia; // enters no negatius
    cin >> numero >> sequencia;
    bool found = false;
    int posicio = 1;
    while (not found and sequencia != -1) {
        if ((numero + sequencia) % 10 == 0) found = true;
        else {
            ++posicio;
            cin >> sequencia;
        }
    }
    if (found) cout << sequencia << ": " << posicio << endl;
    else cout << "No existe" << endl;

}