// programa que transforma xifres parells d'un nombre en aquell senar
// proper seguent

#include <iostream>
using namespace std;

int main () {
    int num; // enters > 0
    cin >> num;
    while (num != 0) {
        int resultat = 0, resultat_real = 0;
        while (num > 0) { // anem numero per numero sumant-li 1 si es parell
            if ((num % 10) % 2 == 0) { 
                resultat = resultat * 10 + ((num % 10) + 1);
            }
            else resultat =( resultat * 10) + (num % 10);
            num /= 10;
        }
        while (resultat > 0) { // ara el girem
            resultat_real = (resultat_real * 10) + (resultat % 10);
            resultat /= 10;
        }
        cout << resultat_real << endl;
        cin >> num;
    }
}