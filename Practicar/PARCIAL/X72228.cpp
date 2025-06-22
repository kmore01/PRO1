// programa que calcula la base que ha de tenir un numero elevat a n tal que
// aquest sigui menor o igual a un altre numero b

#include <iostream>
using namespace std;

int main () {
    int exponencial, num_referencia;
    bool found = false;
    int a = 0, respuesta = 0;
    while (cin >> exponencial >> num_referencia) {
        while (not found and num_referencia != 0) {
            int i = exponencial, resultado = 1;
            ++a;
            // las veces es el error
            while (i > 0) {
                resultado = resultado * a;
                --i;
            }
            if (resultado <= num_referencia) respuesta = a;
            else {
                found = true;
                a = 0;
            }
        }
        if (num_referencia != 0)  cout << respuesta << endl;
        else cout << 0 << endl;
        found = false;
    }
}