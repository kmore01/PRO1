// programa que calcula el maxim d'una sequencia

#include <iostream>
using namespace std;

int main () {
    int numseq; // enteros
    while (cin >> numseq) {
        int numero;
        cin >> numero; // primer nombre per tenir un punt inicial
        int maximo = numero;
        for (int i = 1; i < numseq; ++i) {
            cin >> numero;
            if (numero > maximo) maximo = numero;
        }
        cout << maximo << endl;
    }
}