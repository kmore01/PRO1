// programa que escriu la taula de multiplicar d'un nombre enter

#include <iostream>
using namespace std;

int main () {
    int num;
    cin >> num;
    int i;
    i = 1;
    while (i <= 10) {
        cout << num << '*' << i << " = " << num * i << endl;
        ++i;
    }
}