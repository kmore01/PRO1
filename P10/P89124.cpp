/* Programa que dice si ciertos numeros son primos o no utilizant el Garbell
d’Eratòstenes */

#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1000001; // 10^6

// funcio que diu si un numero es primer
// precondicion: x >= 0
bool es_primer(int x, int divisor = 2) {
    bool primer = false;
    if (x < 2) primer = false; // cas base
    else if (divisor * divisor > x) primer = true; // cas base
    else if (x % divisor == 0) primer = false; // cas base
    else { // cas general
        primer = es_primer(x, divisor + 1);
    }
    return primer;
}

// Funcio que crear un vector amb tots el numeros dient si son primers
vector<bool> eratostenes (int number) {
    vector<bool> aux(number, true);

    for (int i = 2; i <= number; ++i) {
        for (int j = 2 * i; j <= number; j += i) {
            aux[j] = false;
        }       
    }
    return aux;
}


int main () {
    int number;
    vector<bool> list_of_numbers;
    list_of_numbers = eratostenes(MAX);
    while (cin >> number) {
        cout << number;
        if (number <= 1) cout << " no es primer" << endl;
        else {
            if (list_of_numbers[number]) cout << " es primer" << endl;
            else cout << " no es primer" << endl; 
        }
    }
}