/* Programa que diu si les claus i els parentesis tanquen correctament */

#include <iostream>

using namespace std;

// Funcio que retorna si les claus i els parentesis tanquen correctament
bool tanquen_correctament(string sequence) {
    int size = sequence.length(), parentesis = 0, claus = 0;
    for (int i = 0; i < size; ++i) {
        if (sequence[i] == '(') ++parentesis;
        else if (sequence[i] == ')') --parentesis;
        else if (sequence[i] == '[') ++claus;
        else if (sequence[i] == ']') --claus;
    }

    bool veredict;
    if (parentesis == 0 and claus == 0) veredict = true;
    else veredict = false;

    return veredict;
}

int main () {
    string sequence; // '[',']','(', ')'
    while (cin >> sequence) {
        if (tanquen_correctament(sequence)) cout << "si" << endl;
        else cout << "no" << endl;
    }
}