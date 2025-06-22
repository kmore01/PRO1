// programa que calcula el valor d'una sequencia de caracters

#include <iostream>
using namespace std;

int main () {
    char caracter; // lletres
    cin >> caracter;
    int suma = 0;
    while (caracter != '.') {
        if (caracter < 91 and caracter > 64) suma += 'A' - caracter - 1;
        else if (caracter < 123 and caracter > 96) suma += 'z' - caracter + 1;
        cin >> caracter;
    }
    cout << suma << endl;
}