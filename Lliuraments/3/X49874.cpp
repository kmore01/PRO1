// programa que llegeix una seqüència de lletres i diu quina es repeteix i on

#include <iostream>
using namespace std;

int main () {
    char sequencia; // caràcters a, b, c i d
    int a = 0, b = 0, c = 0, d = 0, i = -1; // comptador de lletres i posicio
    while (a < 2 and b < 2 and c < 2 and d < 2 and cin >> sequencia) {
        // bucle per comptar la posició i contem les repeticions de cada lletra
        if (sequencia == 'a') ++a;
        else if (sequencia == 'b') ++b;
        else if (sequencia == 'c') ++c;
        else ++d;
        ++i;
    } 
        if (a == 2) {
            cout << 'a' << ' ' << i << endl;
        }
        else if (b == 2) {
            cout << 'b' << ' ' << i << endl;
        }
        else if (c == 2) { 
            cout << 'c' << ' ' << i << endl;
        }
        else if (d == 2) {
            cout << 'd' << ' ' << i << endl;
        }
}