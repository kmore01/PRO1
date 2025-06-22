// programa que retorna el maxim de 4 nombres enters amb dues funcions

#include <iostream>
using namespace std;

// funcio que calcula el maxim de 2 enters
// Precondicion: enteros
// Postcondicion: entero
int max2(int a, int b) {
    int maximo = a;
    if (b > maximo) maximo = b;
    return maximo;
}

// funcio que calcula el maxim de 4 enters
// Precondicion: enteros 
// Postcondicion: entero
int max4(int a, int b, int c, int d) {
    return max2(max2(a, b), max2(c, d));
}
int main () {
    int a, b, c, d; // enters
    cin >> a >> b >> c >> d;
    cout << max4(a,b,c,d) << endl;
}
