// Programa que calcula cual es la seguna columna más grande representada en
// binario

#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > Matriz;

// Funcion que guarda enteros en una matriz
Matriz leer_en_matriz(int f, int c) {
    Matriz VBinary(f, vector<int>(c));
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> VBinary[i][j];
        }
    }
    return VBinary;
}

int segunda_columna_grande(const Matriz &m) {
    int max, max2;
    for (int j = 0; j < 1; ++j) {
        int i = 0;
        bool found = false;
        while (not found and i < m.size()) {
            if (m[i][j] < m[i][j + 1]) {
                max = j + 1;
                max2 = j;
                found = true;
            }
            else if (m[i][j] > m[i][j + 1]) {
                max = j;
                max2 = j + 1;
                found = true;
            }
            ++i;
        }
    }
    vector<int> num(m[0].size());
    for (int j = 2; j < m[0].size(); ++j) {
        int i = 0;
        bool found = false;
        while (not found and i < m.size()) {
            if (m[i][max] < m[i][j]) {
                max2 = max;
                max = j;
                found = true;
            }
            else if (m[i][max2] < m[i][j]) {
                max2 = j;
                found = true;
            }
            ++i;
        }
    }

    return max2;
}

int main () {
    int filas, columnas;
    while (cin >> filas >> columnas) {
        Matriz sequencia = leer_en_matriz(filas, columnas);
        int solucion = segunda_columna_grande(sequencia);

        for (int i = 0; i < sequencia.size(); ++i) {
            cout << sequencia[i][solucion] << ' ';
        }
        cout << endl;

    }
}