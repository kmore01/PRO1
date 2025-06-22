// Programa que calcula los coeficientes divertidos de dos numeros y el mcd

#include <iostream>
using namespace std;

// Funcion que devuelve el mcd de dos numeros
int mcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

// Pre: a y b son no-negativos. Además a > 0 o b > 0
// Post: calcula la pareja de coeficientes divertidos x e y definidos anteriormente.
// Se cumple xa + yb = mcd(a,b)
void funny_coeffs(int a, int b, int& x, int& y) {
    if (b == 0) { // caso base
        x = 1;
        y = 0;
    }
    else { // caso general
        funny_coeffs(b, (a % b), x, y);
        int temp = x;
        x = y;
        // a / b es el quocient
        y = temp - y * (a / b);
    }
}

int main () {
    int num1, num2; // enteros no negativos
    while (cin >> num1 >> num2) {
        int coeficiente1, coeficiente2;
        funny_coeffs(num1, num2, coeficiente1, coeficiente2);
        cout << coeficiente1 << ' ' << coeficiente2 << ' ' << mcd(num1, num2)   
             << endl;
    }
}