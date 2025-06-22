// programa que indica si un nombre es circular
// un nombre ciruclar es aquell que comença i acaba amb el mateix nombre

#include <iostream>
using namespace std;

int main () {
    int numero; // enters no negatius
    cin >> numero;
    int contador = 0;
    while (numero != -1) {
        int primero = 0, num_guardado = numero;
        while (numero > 0) { // agafo el primer numero del numero introduit
            primero = numero % 10;
            numero /= 10;
        }
        if (num_guardado % 10 == primero) {
            cout << num_guardado << endl;
            ++contador;
        }
        cin >> numero;
    }
    cout << "total: " << contador << endl;
}