// programa que escriu el nombre harmònic: Hn = 1/1 + 1/2 + ⋯ + 1/n

#include <iostream>
using namespace std;

int main () {
    int numero;
    cin >> numero;
    double Hn;
    Hn = 0;
    for (int i = 1; i <= numero; i++) {
        Hn = Hn + (1 / double(i));
    }
    cout.setf(ios::fixed);
    cout.precision(4);
    cout << Hn << endl;
}