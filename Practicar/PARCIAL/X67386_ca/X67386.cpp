// programa que diu a quina posicio es repeteix una paraula a una sequencia

#include <iostream>
using namespace std;

int main () {
    string paraula; // paraula buscada
    cin >> paraula;
    string sequencia; // paraules
    bool found = false;
    int contador = 0;
    while (not found and cin >> sequencia)  {
        if (sequencia == paraula) found = true;
        ++contador;
    }
    if (found) cout << contador << endl;
    else cout << "No existe" << endl;
}