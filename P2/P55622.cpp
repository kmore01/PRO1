// programa que diu el nombre de dígits d'un nombre

#include <iostream>
using namespace std;

int main () {
    int num;
    cin >> num;
    int numdig, numero;
    numdig = 1;
    numero = num;
    while (numero >= 10) {
        numdig = numdig + 1;
        numero = numero / 10;
    }
    cout << "El nombre de digits de " << num << " es " << numdig << '.' << endl;
}