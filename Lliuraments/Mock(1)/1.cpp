// programa que diu si hi ha el promig entre 3 enters

#include <iostream>
using namespace std;

int main () {
    int num, num2, num3; // enters
    cin >> num >> num2 >> num3;
    double suma = double(num) + double(num2) + double(num3);
    if (suma / 3 == num or suma / 3 == num2 or suma / 3 == num3) cout << "YES" << endl;
    else cout << "NO" << endl;

}