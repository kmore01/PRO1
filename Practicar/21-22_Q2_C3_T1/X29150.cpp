// Programa que mira si una matriz es de Hankels. Notemos que las matrices de
// Hankel se caraterizan por tener un valor constante en cada diagonal
// perpendicular a la diagonal principal

#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int> > MatrizChar; 

// Funcion que guarda enteros en una matriz cuadrada
MatrizChar leer_en_matriz() {
    int size; // entero > 0
    cin >> size;
    MatrizChar VNum(size, vector<int>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cin >> VNum[i][j];
        }
    }
    return VNum;
}

// Funcion que devuelve true si la matriz es de Hankel y devuelve falso en el
// caso contrario
bool is_hankel(MatrizChar VNumeros) {
    for (int i = 1; i < VNumeros.size(); ++i) {
        for (int j = 0; j < VNumeros[0].size() - 1; ++j) {
            if (VNumeros[i][j] != VNumeros[i - 1][j + 1]) return false;
        }
    }

    return true;
}


int main () {
    int num_matrices; // entero no negativo
    cin >> num_matrices;
    for (int i = 0; i < num_matrices; ++i) {
        MatrizChar input = leer_en_matriz();
        if (is_hankel(input)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}