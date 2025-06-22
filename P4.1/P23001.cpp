// programa que diu quantes vegades es repetida una paraula seguida

#include <iostream>
using namespace std;

int main () {
    string mare, paraules; // paraules
    cin >> mare;
    int contador = 1, maximo = 1;
    while (cin >> paraules) {
        // si la paraula es la mateixa suma un, sino el contador es restableix
        if (paraules == mare) {
            ++contador;
            if (maximo < contador) maximo = contador;
        }
        else contador = 0;
    }
    cout << maximo << endl;
}