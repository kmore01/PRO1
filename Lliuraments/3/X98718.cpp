// programa que calcula que combinacio de 3 caracteres es repeteix i la posicio

#include <iostream>
using namespace std;

int main () {
    char sequencia; // caracters a, b
    int contador = -3, contador1 = 0, contador2 = 0, contador3 = 0, contador4 = 0, contador5 = 0, contador6 = 0, contador7 = 0, contador8 = 0;
    char letra1 = ' ', letra2 = ' ', letra3 = ' ';
    bool encontrado = false;
    char resultado1 = ' ', resultado2 = ' ', resultado3 = ' ';
    // bucle mentre no trobi la repeticio
    while (not encontrado and cin >> sequencia) {
        if (contador != -3) {
            letra1 = letra2;
            letra2 = letra3;
            letra3 = sequencia;
        }
        else letra3 = sequencia;
        // condicionals que sumen 1 per cada repeticio d'una combinacio
        if (letra1 == 'a') {
            if (letra2 == 'a') {
                if (letra3 == 'a') ++contador1;
                else if (letra3 == 'b') ++contador2;
            }
            else if (letra2 == 'b') {
                if (letra3 == 'a') ++contador3;
                else if (letra3 == 'b') ++contador4;
            }
        }
        else if (letra1 == 'b') {
            if (letra2 == 'a') {
                if (letra3 == 'a') ++contador5;
                else if (letra3 == 'b') ++contador7;
            }
            else if (letra2 == 'b') {
                if (letra3 == 'a') ++contador8;
                else if (letra3 == 'b') ++contador6;
            }
        }
        // si algun contador supera 1 significa que la busqueda ha terminat
        if (contador1 > 1 or contador2 > 1 or contador3 >1 or contador4 > 1 or contador5 > 1 or contador6 > 1 or contador7 > 1 or contador8 > 1) {
            encontrado = true;
            resultado1 = letra1;
            resultado2 = letra2;
            resultado3 = letra3;
        }
        ++contador;
    }
    cout << resultado1 << resultado2 << resultado3 << ' ' << contador << endl;
}