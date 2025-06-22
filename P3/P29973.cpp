// programa que fa un triangle de mida d'un nombre natural > 0

#include <iostream>
using namespace std;

int main () {
    int num; // natural > 0
    cin >> num;
    for (int i = 1; i <= num; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << '*';
        }
        cout << endl;
    }
}