// programa que compta els passos per arribar a 1 amb la seqüència de Collatz

#include <iostream>
using namespace std;

int main () {
    int num; // natural ≥ 1
    while (cin >> num) {
        int i = 0, j = 0;
        while (num != 1) {
            // senars
            if (num % 2 != 0) {
                num = num * 3 + 1;
                ++i;
            }
            // parells
            while (num % 2 == 0) {
                num /= 2;
                ++j;
            }
        }
        cout << i + j << endl;
    }
}