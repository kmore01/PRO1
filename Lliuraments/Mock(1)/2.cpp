// programa que diu els pics que te un nombre

#include <iostream>
using namespace std;

int main () {
    int num; // natural > 0
    int contador = 0;
    while (cin >> num) {
        int num1, med, num3;
        contador = 0;
        if (num / 100 != 0) {
            num1 = num % 10;
            num /= 10;
            med = num % 10;
            num /= 10;
            num3 = num % 10;
            if (med > num1 and med > num3) ++contador;
            num /= 10;
            while (num > 0) {
                num1 = med;
                med = num3;
                num3 = num % 10;
                if (med > num1 and med > num3) ++contador;
                num /= 10;
            }
        }
        cout << contador << endl;
    }
}