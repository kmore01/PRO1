// programa que calcula los numeros que acaban por las mismas 3 cifras que otro

#include <iostream>
using namespace std;

int main () {
    int numero_base, num; // naturales ≥ 100
    cin >> numero_base;
    int contador = 0;
    cout << "nombres que acaben igual que " << numero_base << ':' << endl;
    while (cin >> num) {
        if (numero_base % 1000 == num % 1000) {
            cout << num << endl;
            ++contador;
        }
    }
    cout << "total: " << contador << endl;
}