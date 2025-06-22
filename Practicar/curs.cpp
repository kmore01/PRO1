#include <iostream>
using namespace std;

void generate(int num) {
    if (num == 0) cout << 0;
    else {
        for (int i = 0; i < num; ++i) {
            if (i == 0) cout << num;
            generate(num - 1);
            cout << num;
        }
    }
}

int main () {
    int numero;
    while (cin >> numero) {
        generate(numero);
        cout << endl;
    }
}