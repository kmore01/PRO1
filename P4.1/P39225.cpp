// programa que escriu el numero que hi ha a la posicio introduida

#include <iostream>
using namespace std;

int main () {
    int posicio; // enter
    cin >> posicio;
    int num, i = 0;
    while (i < posicio and cin >> num) { // sortira del bucle quan i = posicio
        ++i;
    }
    cout << "A la posicio " << posicio << " hi ha un " << num << '.' << endl;
}