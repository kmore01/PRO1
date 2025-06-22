// programa que suma els digits d'un nombre

#include <iostream>
using namespace std;

int main () {
    int num;
    while (cin >> num) {
        cout << "La suma dels digits de " << num << " es ";
        int resultat = 0;
        while (num > 0) {
            resultat = resultat + num % 10;
            num = num / 10;
        }
        cout << resultat << '.' << endl;
    }
}