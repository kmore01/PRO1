// programa que llegeix un natural ≥ 1 i escriu la figura corresponent

#include <iostream>
using namespace std;

int main () {
    int num; // natural ≥ 1
    cin >> num;
    for (int i = 0; i < num; ++i) { // files
        for (int j = num - (1+i); j > 0; --j) { // imprimir '+'
            cout << '+';
        }
        cout << '/';
        for (int j = 0; j < i; ++j) { // imprimir '*'
            cout << '*';
        }
        cout << endl; // saltar de linea
    }
}