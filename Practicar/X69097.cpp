/* Programa que ordena las filas de una matriz de ceros y unos */

#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<int> > MatrizChar;

MatrizChar read_in_matrix (int filas, int columnas) {
    MatrizChar chest(filas, vector<int>(columnas));
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cin >> chest[i][j];
        }
    }
    return chest;
}

// Procedimiento para intercambiar filas
void intercambiar_filas (MatrizChar &a, int i, int k) {
    for (int p = 0; p < a[0].size(); ++p) {
        int temporal = a[i][p];
        a[i][p] = a[k][p];
        a[k][p] = temporal;
    }
}

void ordenar(MatrizChar &a) {
    bool intercambiar = true;
    while (intercambiar) {
        intercambiar = false;
        for (int i = 0; i < a.size() - 1; ++i) {
            if (a[i][0] == 1 and a[i + 1][0] == 0) {
                intercambiar_filas(a, i, i + 1);
                intercambiar = true;
            } else if (a[i][0] != 1 and a[i + 1][0] != 1) {
                int j = 1;
                bool found = false;
                while (j < a[0].size() and not found) {
                    if (a[i][j] < a[i + 1][j]) {
                        intercambiar_filas(a, i, i + 1);
                        found = true;
                        intercambiar = true;
                    }
                    ++j;
                }
            } else if (a[i][0] == 1 and a[i + 1][0] == 1) {
                int j = 1;
                bool found = false;
                while (j < a[0].size() and not found) {
                    if (a[i][j] > a[i + 1][j]) {
                        intercambiar_filas(a, i, i + 1);
                        found = true;
                        intercambiar = true;
                    } else if (a[i][j] < a[i + 1][j]) {
                        found = true;
                    }
                    ++j;
                }
            }
        }
    }
}


// Procedimiento para imprimir la matriz
void imprimir (MatrizChar &a) {
    int filas = a.size(), columnas = a[0].size();
    for (int i = 0; i < filas; ++i) {
        cout << a[i][0];
        for (int j = 1; j < columnas; ++j) {
            cout << ' ' << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main () {
    int filas, columnas;
    while (cin >> filas >> columnas) {
        MatrizChar matriz_a_ordenar = read_in_matrix(filas, columnas);
        ordenar(matriz_a_ordenar);

        imprimir(matriz_a_ordenar);
    }
}