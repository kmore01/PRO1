// programa que dice si en una sequencia de caracteres aparece la palabra hola

#include <iostream>
using namespace std;

int main () {
    char letra;
    cin >> letra;
    bool encontrado = false;
    while (not encontrado and letra != '.') { 
        if (letra == 'h') {
            cin >> letra;
            if (letra == 'o') {
                cin >> letra;
                if (letra == 'l') {
                    cin >> letra;
                    if (letra == 'a') {
                        encontrado = true;
                    }
                } 
            } 
        }
        else cin >> letra;
    }
    if (encontrado) cout << "hola" << endl;
    else cout << "adeu" << endl;
}