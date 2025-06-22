// programa que avalua si són certes o no diverses comparacions

#include <iostream>
using namespace std;

int main () {
    int num1, num2, num3; // naturals
    char operador;
    string comparador;
    while (cin >> num1 >> operador >> num2 >> comparador >> num3) {
        // obtenim el resultat dels nombres segons l'operador
        int resultat;
        if (operador == '+') {
            resultat = num1 + num2;
        }
        else if (operador == '-') {
            resultat = num1 - num2;
        }
        else {
            resultat = num1 * num2;
        }
        // estudiem cada cas
        bool sip = false;
        if (comparador == ">") {
            sip = resultat > num3;
        }
        else if (comparador == "<") {
            sip = resultat < num3;
        }
        else if (comparador == "==") {
            sip = resultat == num3;
        }
        else if (comparador == "!=") {
            sip = resultat != num3;
        }
        else if (comparador == ">=") {
            sip = resultat >= num3;
        }
        else {
            sip = resultat <= num3;
        }
        
        if (sip) {
            cout << "true" << endl;
        }
        else {
            cout << "false" << endl;
        }
    }
}