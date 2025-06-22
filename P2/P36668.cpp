// programa que escriu el sumatori dels quadrats d'un nombre

#include <iostream>
using namespace std;

int main () {
    int num;
    cin >> num;
    int result = 0;
    for (int i = 1; i <= num; ++i) {
        result = result + i * i;
    }
    cout << result << endl;
}