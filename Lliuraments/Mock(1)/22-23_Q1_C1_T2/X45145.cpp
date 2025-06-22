// programa que diu els nombres imparells d'uns enters no negatius

#include <iostream>
using namespace std;

int main () {
    int numero; // enter positiu
    cin >> numero;
    while (numero != -1) {
        int num2 = 0;
        int resultado = 0;
        while (numero > 0) { // girar el nombre
            num2 = num2 * 10 + numero % 10;
            numero /= 10; 
        }
        while (num2 > 0) { // comprobar cada posicio
            if ((num2 % 10) % 2 != 0) resultado = resultado * 10 + num2 % 10;
            num2 /= 10;
        }
        cout << resultado << endl;
        cin >> numero;
    }
}