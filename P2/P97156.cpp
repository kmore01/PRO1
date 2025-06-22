// programa que imprimeix els nombres que hi ha entre dos nombres 

#include <iostream>
using namespace std;

int main () {
    int num1, num2;
    cin >> num1 >> num2;
    int i;
    i = num1;
    while (i <= num2) {
        cout << i;
        if (i < num2) cout << ',';
        i = i + 1;
    }
    cout << endl;
}