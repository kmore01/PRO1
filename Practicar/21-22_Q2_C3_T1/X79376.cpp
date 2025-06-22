// Programa que escribe las dos mediciones mas altas de reciclaje
// en cada ciudad

#include <iostream>

using namespace std;

// Procedimiento para calcular los dos numeros maximos de reciclaje
// y imprimir la solucion
void calcular_imprimir() {
    int num, max = -1, max2 = -1;
    cin >> num;
    while (num != -1) {
        if (num >= max) {
            max2 = max;
            max = num;
        }
        else if (num > max2) max2 = num;
        cin >> num;
    }
    cout << max << ' ' << max2 << endl;
} 

int main () {
    string ciudad;
    while (cin >> ciudad) {
        cout << ciudad << ": ";
        calcular_imprimir();
    }
}