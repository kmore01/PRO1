// programa que imprimeix tots els nombres de 0 al nombre natural introduit

#include <iostream>
using namespace std;

int main () {
    int num;
    cin >> num;
    for (int i = 0; i <= num; ++i) {
        cout << i << endl;
    }
}