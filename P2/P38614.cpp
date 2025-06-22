// programa que diu si un nombre és txatxi (suma dels dígits senars és parell)

#include <iostream>
using namespace std;

int main () {
    int a;
    cin >> a;
    int numero2, numdig, k, n;
    numero2 = a;
    numdig = 0;
    k = 0;
    n = 0;
    while (numero2 >= 1) {
        numdig = numdig + 1;
        k = numero2 % 10;
        numero2 = numero2 / 10;
        if (numdig % 2 != 0) n = n + k;
    }
    if ((n % 2) == 0) {
        cout << a << " ES TXATXI" << endl;
    }
    else {
        cout << a << " NO ES TXATXI" << endl;
    }
}