// un numero es primo perfecto si el numero dado es primo y la suma
// de sus digitos es primo perfecto;
// 3 funciones recursivas + main

#include <iostream>
using namespace std;

// funcio que diu si un numero es primer
// precondicion: x >= 0
bool es_primer(int x, int divisor = 2) {
    if (x < 2) return false; // cas base
    else if (divisor * divisor > x) return true; // cas base
    else if (x % divisor == 0) return false; // cas base // dos canvias por div y quitas el de abajo
    else { // cas general
        return es_primer(x, divisor + 1);
    }
}

// funcio que suma els digits d'un numero
int suma_digits(int n) {
    if (n < 10) return n; // cas base
    else return n % 10 + suma_digits(n / 10); // cas general
}

// funcio que diu si un numero es primer perfecte
bool es_primer_perfecte(int n) {
    bool primer = es_primer(n);
    if (n < 10) return primer; // cas base
    else { // cas general
        return primer and es_primer(suma_digits(n)) and es_primer_perfecte(suma_digits(n));
    }
}

int main () {
    int num;
    cin >> num;
    if (es_primer(num)) cout << "true" << endl;
    else cout << "false" << endl;
}