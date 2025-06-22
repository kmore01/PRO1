// Programa que calcula el numero total de submatrices no-vacias, cuadradas y
// constantes, es decir, con tantas filas como columnas i con el mismo símbolo

#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<char> > MatrizChar; 
typedef vector<vector<int> > MatrizInt; 

// Funcion que guarda enteros en una matriz cuadrada
MatrizChar leer_en_matriz(int filas, int columnas) {
    MatrizChar VNum(filas, vector<char>(columnas));
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cin >> VNum[i][j];
        }
    }

    return VNum;
}

// Funcion que devuelve el elemento minimo entre tres enteros
int min_elem(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;

    return min;
}

// Funcion que devuelve cierto si en la fila [i] y columna [j] hay una
// submatriz con los elementos de arriba a la izquierda
bool es_submatriz(const MatrizChar &a, int i, int j) {
    char elem = a[i][j];
    bool subm = false;
    // Comprobamos si es una submatriz 2x2 mirando que los elementos sean iguales
    if (i >= 1 and j >= 1) {
        if (a[i - 1][j - 1] == elem and a[i - 1][j] == elem and a[i][j - 1] == elem) subm = true;

    }

    return subm;
}

// Funcion que cuenta las submatrices que hay en la fila i y la columna j
int contar_submatrices(const MatrizChar &input, int i, int j, const MatrizInt &b) {
    int count = 0;
    if (es_submatriz(input, i, j)) {
        count = min_elem(b[i - 1][j - 1], b[i - 1][j], b[i][j - 1]) + 1; 
    }

    return count;
}

// Procedimiento que calcula el numero total de submatrices
void numero_total_submatrices(const MatrizChar &input, MatrizInt &b, int &total) {
    for (int i = 0; i < b.size(); ++i) {
        for (int j = 0; j < b[0].size(); ++j) {
            b[i][j] += contar_submatrices(input, i, j, b);
            total += b[i][j];
        }
    }
}

int main () {
    int filas, columnas; // entero > 0
    while (cin >> filas >> columnas) {
        MatrizChar sequencia = leer_en_matriz(filas, columnas);
        //
        MatrizInt b(filas, vector<int>(columnas));
        // Calculas las submatrices 1x1
        int total = filas * columnas;
        numero_total_submatrices(sequencia, b, total);
        cout << total << endl;
    }
}