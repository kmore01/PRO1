// Programa que cuenta cuantas banderas en forma de matriz cumplen 2
// requisitos: En la columna existe una posicion, que no puede ser la primera, y
// solo una que cambia el color respecto al color que tiene encima.
// La posicion de cambio de color tiene que estar la diagonal secundaria o por debajo de ella.

#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char> > Flag; 

Flag read_flag(int size) {
    Flag Bandera(size, vector<char>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cin >> Bandera[i][j];
        }
    }

    return Bandera;
}

bool es_diagonal_secundaria(const Flag &bandera, int i, int j) {
    for (int k = bandera.size() - 1; k > 0; --k) {
        for (int q = 0; q < bandera[0].size(); ++q) {
            if (i >= k and j > k) return false;
        }
    }

    return true;
}

int column_count(Flag &bandera) {
    int count = 0;
    for (int j = 0; j < bandera[0].size(); ++j) {
        int repe = 0;
        for (int i = 1; i < bandera.size(); ++i) {
            // Comprobamos la primera condicion
            if (repe == 0 and bandera[i][j] != bandera[i][j - 1]) {
                ++repe;
                // Comprobamos la segunda condicion
                if (es_diagonal_secundaria(bandera, i, j)) {
                    ++count;
                    cout << "Columna:" << j << endl;
                }
            }
        }
    }

    return count;
}

int main() {
    int n;
    while (cin >> n) {
        Flag flag = read_flag(n);
        cout << column_count(flag) << endl;
    }
}