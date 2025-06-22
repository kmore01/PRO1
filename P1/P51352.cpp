//programa que diu qui guanya l'enfrontament entre aigua (A) pedra (P) i vent (V)

#include <iostream>
using namespace std;

int main () {
    char k, m;
    cin >> k >> m;
    
    if ((k == 'A' and m == 'P') or (k == 'P' and m == 'V') or (k == 'V' and m == 'A')) cout << 1 << endl;
    else if ((k == 'A' and m == 'V') or (k == 'P' and m == 'A') or (k == 'V' and m == 'P')) cout << 2 << endl;
    else {
        cout << "-" << endl;
    }
}