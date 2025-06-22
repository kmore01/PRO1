// programa que escriu la suma dels dígits d'un nombre en una base especifica

#include <iostream>
using namespace std;

int main () {
    int base;
    cin >> base;
    int elem;
    while (cin >> elem) {
        cout << elem << ": ";
        int resultat = 0;
        while (elem > 0) {
            resultat = resultat + elem % base;
            elem = elem / base;
        }
        cout << resultat << endl;
    }
}