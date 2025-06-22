// programa que suma els cubs entre dos nombres

#include <iostream>
using namespace std;

int main () {
    int num1, num2;
    while (cin >> num1 >> num2) { // bucle perquè no s'acabi mai
        int sumacub = 0;
        for (int i = num1; i <= num2; ++i) { // fem un bucle que suma els cubs de cada nombre fins a arribar a num2
            sumacub = sumacub + (i * i * i);
        }
        cout << "suma dels cubs entre " << num1 << " i " << num2 << ": " << sumacub << endl;
    }
}