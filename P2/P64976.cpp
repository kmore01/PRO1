// programa que escriu la taula de multiplicar fins al nombre introduït

#include <iostream>
using namespace std;

int main () {
    int num;
    cin >> num;
    for (int i = 1; i <= num; ++i) {
        cout << num << " x " << i << " = " << num * i << endl;
    }
}