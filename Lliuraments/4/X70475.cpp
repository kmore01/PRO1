// programa que defineix el nivell de felicitat i trsitesa

#include <iostream>
using namespace std;

int main () {
    char sequencia; // caracaters
    int contador_feliz = 0, contador_triste = 0;
    char caracter1 = ' ', caracter2 = ' ';
    cin >> caracter1 >> caracter2;

    while (cin >> sequencia) {
        char sequencia_bucle = sequencia;
        if (sequencia == '-' and caracter2 == '-') {
            while (cin >> sequencia and sequencia == '-') {}
            sequencia_bucle = sequencia;
        }

        if ((caracter1 == ':' and caracter2 == '-' and sequencia_bucle == ')') or (caracter1 == '(' and caracter2 == '-' and sequencia_bucle == ':')) ++contador_feliz;
        else if ((caracter1 == ':' and caracter2 == '-' and sequencia_bucle == '(') or (caracter1 == ')' and caracter2 == '-' and sequencia_bucle == ':')) ++contador_triste;
    
        caracter1 = caracter2; // anem agafant un nou caracter cada cicle
        caracter2 = sequencia_bucle;
    }
    cout << contador_feliz << ' ' << contador_triste << endl;
}