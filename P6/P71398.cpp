// programa que calcula el maxim i el minim d'un numero

#include <iostream>
using namespace std;

// funcio que calcula el maxim i el minim
// precondicio: n ≥ 0
void digit_maxim_i_minim(int n, int &maxim, int &minim) {
    if (n < 10) { // cas base
        maxim = n;
        minim = n;
    }
    else { // cas general
        digit_maxim_i_minim(n / 10, maxim, minim);
        if (n % 10 > maxim) maxim = n % 10;
        else if (n % 10 < minim) minim = n % 10;
    }
}

int main () {
    int numero;
    cin >> numero;
    int maxim, minim;
    digit_maxim_i_minim(numero, maxim, minim);
    cout << maxim << ' ' << minim << endl;
}