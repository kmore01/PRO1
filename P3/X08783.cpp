// programa que calcula el nombre de xifres en diverses bases 

#include <iostream>
using namespace std;

int main () {
    int num, base;
    while (cin >> base >> num) {
        int i = 0;
        int resultat = num;
        while (num > 0) {
            resultat = resultat % base;
            num = num / base;
            ++i;
        }
        cout << i << endl;
    }
}