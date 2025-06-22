// Programa que cuenta el numero de veces que aparece un elemento en su fila y
// columna

#include <iostream>
#include <vector>
using namespace std; 

typedef vector<vector<int> > Matriz;

// Lee los caracteres y los guarda en una matriz pasandolos a enteros.
// Ademas, cuenta cuantas veces se repite cada valor en cada fila y columna
void leer_en_matriz_extenso(Matriz &VNum, Matriz &fil, Matriz &col, int f, int c) {
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            // Como los numeros no estan separados y por tanto, los tenemos que leer como caracteres, los pasamos a enteros
            char elemento;
            cin >> elemento;
            int d = elemento - '0';
            VNum[i][j] = d;
            // fil contiene el numero de veces que aparece *d* en la fila i
            ++fil[i][d];
            // col contiene el numero de veces que aparece *d* en la columna j
            ++col[j][d];
        }
    }
}

// Procedimiento que recorre la matriz sumando las veces que aparece el
// elemento en la fila y columna utilizando los previos calculos realizados
void sumar_repeteciones_imprimir(const Matriz &m, Matriz &solucion, Matriz &fil, Matriz &col) {
    // Primera parte: Contar ocurrencias sumando cuantas veces aparece el
    // elemento en la fila y columna pertinente
    // Hacemos el modulo con 10 por ENUNCIADO
    for (int i = 0; i < solucion.size(); ++i) {
        for (int j = 0; j < solucion[0].size(); ++j) {
            int d = m[i][j];
            solucion[i][j] = (fil[i][d] + col[j][d]) % 10;
        }
    }

    // Segunda parte: Imprimir la solucion
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
        // Creamos dos matrices que contengan cuantas veces aparece x digito en
        // una fila y columna y lo inicializamos a 0.
        Matriz fil2d(filas, vector<int> (10, 0));
        Matriz col2d(columnas, vector<int> (10, 0));

        leer_en_matriz_extenso(input, fil2d, col2d, filas, columnas);

        Matriz solucion(filas, vector<int>(columnas));
        sumar_repeteciones_imprimir(input, solucion, fil2d, col2d);
    }
}