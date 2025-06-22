// programa que escribe la segunda palabra mas grande alfabeticamente

#include <iostream>
using namespace std;

int main () {
    string palabra; // palabra
    cin >> palabra;
    string mayor = palabra, segunda = "";
    while (cin >> palabra) {
        if (palabra != mayor) { // para evitar repeticiones de palabras, solo hay problemas con las grandes
            if (segunda == "") segunda = palabra; // no hay asignado un texto
            else if (palabra > segunda) segunda = palabra; // mira la mas grande
        }
        if (palabra > mayor) { 
            // si la nueva palabra es mas grande significa que la anterior mayor es ahora la segunda
            segunda = mayor;
            mayor = palabra;
        }
    }
    cout << segunda << endl;
}