// programa que calcula la posició final d'un objecte

#include <iostream>
using namespace std;

int main () {
    char instruccio; // caracter
    int est_oest = 0, sud_nord = 0;
    while (cin >> instruccio) { // bucle amb condicions segons la lletra posada
        if (instruccio == 's') ++sud_nord;
        else if (instruccio == 'n') --sud_nord;
        if (instruccio == 'e') ++est_oest;
        else if (instruccio == 'o') --est_oest;
    }
    cout << '(' << est_oest << ", " << sud_nord << ')' << endl;
}