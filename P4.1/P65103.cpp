// programa que escriu el numero que hi ha en una posicio si existeix

#include <iostream>
using namespace std;

int main () {
    int posicio; // enter
    cin >> posicio;
    int num, i = 0;
    while (i < posicio and cin >> num) {
        ++i;
    }
    if (i == posicio and i != 0) { // existeix un numero en la posicio
        cout << "A la posicio " << posicio << " hi ha un " << num << '.' << endl;
    }
    else cout << "Posicio incorrecta." << endl; // no existeix 
}