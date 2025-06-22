// Programa que cuenta cuantas veces aparece un numero en una matriz

#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > Matriz;

void leer_matriz(Matriz &m, Matriz &fil, Matriz &col, int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            char c;
            cin >> c;
            // Convertimos el caracter a entero para guardarlo
            int elem = c -'0' ;
            m[i][j] = elem;
            ++fil[i][elem];
            ++col[j][elem];
        }
    }
}

void contar_imprimir(const Matriz &m, const Matriz &fil, const Matriz &col, Matriz &solucion) {
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[0].size(); ++j) {
            int d = m[i][j];
            solucion[i][j] = (fil[i][d] + col[j][d]) % 10;
        }
    }

    for (int i = 0; i < solucion.size(); ++i) {
        for (int j = 0; j < solucion[0].size(); ++j) {
            cout << solucion[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main () {
    int filas, columnas;
    while (cin >> filas >> columnas) {
        Matriz input(filas, vector<int>(columnas));
        // Creamos dos matrices que contengan los elementos que aparacen en
        // cada fila y columna
        Matriz fil2d(filas, vector<int>(10, 0));
        Matriz col2d(columnas, vector<int>(10, 0));
        leer_matriz(input, fil2d, col2d, filas, columnas);
        Matriz solucion(filas, vector<int>(columnas));
        contar_imprimir(input, fil2d, col2d, solucion);
    }
}