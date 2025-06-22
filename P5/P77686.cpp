// programa que diu si un nombre es capicua o no
// capicua es aquell nombre que de dreta a esquerra es el mateix que de
// esquerra a dreta
#include <iostream>
using namespace std;

// funcio que calcula si un natural es capicua
// Precondicion: natural
// Postcondicion: bool
bool es_capicua(int n) {
    int residuo = n;
    int numero = 0;
    while (residuo > 0) {
        numero = (numero * 10) + residuo % 10;
        residuo /= 10;
    }
    return (numero == n);
}

int main () {
    int n;
    cin >> n;
    if (es_capicua(n) == 1) cout << "true" << endl;
    else cout << "false" << endl;
}
