// donat un número major que 1, el programa diu quantes xifres es necessiten per representar-lo en base 2 fins a 16

#include <iostream>
using namespace std;

int main () {
    int numero;
    cin >> numero;
    for (int base = 2; base <= 16; ++base) { // fem un bucle per treure una part de la frase i pujar 1 base quan es repeteixi el bucle
        cout << "Base " << base << ": ";
        int cifras = 0;
        for (int div = numero; div != 0; ++cifras) { // bucle per a cada valor de base i ho dividim comptant quantes vegades ho ha fet per saber les xifres necessàries
            div = div / base;
        }
        cout << cifras << " cifras." << endl;
    }
}   