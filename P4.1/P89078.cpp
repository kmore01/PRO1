// programa que indica el primer numero parell d'una sequencia

#include <iostream>
using namespace std;

int main () {
    int num; // naturals
    int i = 0, residuo = 1;
    while (residuo != 0 and cin >> num) {
        ++i;
        residuo = num % 2;
    }
    cout << i << endl;
}