// Programa que calcula si dos enteros son pareja de potencias

#include <iostream>

using namespace std;

// Pre: n >= 0, base > 1
// Post: returns true when n is a power of base. 
// returns false otherwise.
bool is_power(int n, int base) {
    if (n == 1) return true;
    if (n == base) return true;
    int elemento = 1;
    while (elemento < n) {
        elemento *= base;
        if (elemento == n) return true;
    }

    return false;
}

int main () {
    int numero, numero2;
    while (cin >> numero >> numero2) {
        int count = 0;
        while (numero2 != 0) {
            int i = 2;
            bool found = false;
            if (numero == 1) ++count;
            while (not found and i <= numero) {
                if (is_power(numero, i) and is_power(numero2, i)) {
                    ++count;
                    found = true;
                }
            ++i;
            }
            numero = numero2;
            cin >> numero2;
        }
        cout << count << endl;
    }
}