// programa que busca un digit en un enter i diu si apareix vegades parelles

#include <iostream>
using namespace std;

int main () {
    int digit_cercat; //  0 ≤ digit_cercat ≤ 9
    cin >> digit_cercat;
    bool parell = false;
    int elem, num; // enter > 0
    while (not parell and cin >> elem) {
        int contador = 0;
        num = elem;
        while (elem > 0) { // bucle per revisar cada nombre
            if (elem % 10 == digit_cercat) ++contador;
            elem /= 10;
        }    
        if (contador % 2 == 0) parell = true;
    }
    if (parell) cout << num << endl;
    else cout << "no d-par" << endl;
}