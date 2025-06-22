// programa que imprimeix sequencies de rombes a partir de dos nombres

#include <iostream>
using namespace std;

int main () {
    int numspaces, numrombe; // naturals > 0
    while (cin >> numspaces >> numrombe) {
        // PART ALTA DEL ROMBE
        for (int i = 0; i < numspaces; ++i) cout << ' '; // espais inicials
        cout << '*' << endl;
        for (int rombes = 1; rombes <= numrombe; ++rombes) { // bucle per rombes
            int espais_mitjans = 1;
            // PART MITJANA ALTA DEL ROMBE
            for (int i = 0; i < numspaces - 1; ++i) {
                for (int j = 1 + i; j < numspaces; ++j) { // espais inicials
                    cout << ' ';
                }
                cout << '*';
                for (int k = 0; k < espais_mitjans; ++k) { // espais mitjans
                    cout << ' ';
                }
                cout << '*' << endl;
                espais_mitjans += 2;
            }
            // PARTE MITJANA
            cout << '*';
            for (int i = 0; i < 2 * numspaces - 1; ++i) cout << ' '; // espais
            cout << '*' << endl;
            // PARTE MITJANA BAIXA
            for (int i = numspaces - 1; i > 0; --i) {
                for (int k = 0; k < numspaces - i; ++k) { // espais inicials
                    cout << ' ';
                }
                cout << '*';
                for (int j = i * 2 - 1; j > 0; j -= 1) { // espais mitjans
                    cout << ' ';
                }
                cout << '*' << endl;
            }
            // TANCAMENT I APERTURA DEL ROMBE
            for (int i = 0; i < numspaces; ++i) cout << ' ';
            cout << '*' << endl;
            if (rombes == numrombe) cout << endl;
        }
    }
}