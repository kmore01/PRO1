// programa que llegeix un enter estrictament positiu x i una seqüència d’enters, i que diu quants elements hi ha a la seqüència que son múltiples de x

#include <iostream>
using namespace std;

int main () {
    int num;
    cin >> num;
    int elem, veg = 0;
    while (cin >> elem) { // fem un bucle per llegir tots els elements un a un
        if (elem % num == 0) { // si són múltiples sumem 1 al comptador
            ++veg;
        }
    }
    cout << veg << endl;
}