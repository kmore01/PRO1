// programa que escriu un triangla en base a la seva mida

#include <iostream>
using namespace std;

int main () {
    int mida; // enter > 1
    cin >> mida;
    for (int j = mida; j > 0; --j) {
        cout << '*';
    }
    cout << endl;
    for (int i = 1; i < mida; ++i) {
        for (int j = i; j > 0; --j) { // espais inicials
            cout << ' ';
        }
        cout << '*';
        for (int k = mida - 2 - i; k > 0; --k) { // espais intermitjos
            cout << ' ';
        }
        if (i + 1 != mida) cout << '*';
        cout << endl;
    }
}