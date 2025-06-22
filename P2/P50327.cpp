// programa que llegeix un nombre natural i l'escriu del revés

#include <iostream>
using namespace std;

int main () {
    int num;
    cin >> num;
    int mod;
    mod = num;
    while (mod >= 10) {
        cout << mod % 10;
        mod = mod / 10;
    }
    cout << mod << endl;
}