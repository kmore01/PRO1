// programa que escriu el primer element el seu valor es la meitat del maxim
// dels elements que esta a la seva esquerra i separen un numero parell
// d’elements d’aquest maxim. En cas que el maxim a l’esquerra d’una element
// estigui repetit, es tindra en compte la primera posicio a la que va apareixer

#include <iostream>
using namespace std;

int main () {
    int num; // sequencia no buida d'enters no negatius
    bool found = false;
    int posicio = 0;
    int max = -1; // cas frontera 0
    while (not found and cin >> num) {
        if ((2 * num) == max and (posicio % 2) == 0) found = true; // condicio
        if (num > max) {
            max = num;
            posicio = 0;
        }
        else ++posicio;
    }
    if (found) cout << num << endl;
    else cout << "no existe" << endl;
}