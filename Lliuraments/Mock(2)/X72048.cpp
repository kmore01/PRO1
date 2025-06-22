// Programa que escribe una sequencia de numeros segun el numero inicial

#include <iostream>

using namespace std;

// Procedimiento que imprime la respuesta
void generateLine(int num) {
    if (num == 0) cout << 0; // caso base
    else { // caso general
        for (int i = num; i > 0; --i) {
            if (i == num) cout << num;
            generateLine(num - 1);
            cout << num;
        }
    }
}

int main() {
    int num_subsequences;
    while (cin >> num_subsequences) {
        generateLine(num_subsequences);
        cout << endl;
    }
}