// programa que escriu un rectangle de mida n x m

#include <iostream>
using namespace std;

int main () {
    int n, m; // naturals > 0
    int pos = 0;
    while (cin >> n >> m) {
        if (pos != 0) cout << endl;
        int aux = 0;
        for (int i = 0; i < n; ++i) { // columnes
            for (int j = m; j > 0; --j) { // files
                cout << 9 - aux;
                ++aux;
                if (aux == 10) {
                    aux = 0;
                }
            }
            cout << endl;
        }
        if (pos == 0) pos = 1;
    }
}