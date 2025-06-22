// Programa que calcula una variante gamma, epsilon y consumo de una matriz
// representada por numeros binarios

#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> Binario;
typedef vector<Binario> MatrizChar;

// Pre: n > 0, m > 0
// Post: retorna una matriz de '0' y '1' con dimensiones n*m leída de la entrada
MatrizChar leer_matriz(int n, int m) {
    MatrizChar VBinario(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> VBinario[i][j];
        }
    }
    return VBinario;
}

// Pre: -
// Post: escribe el string s, seguido por dos punts, seguido por el Binario b
void escribir(string s, const Binario& b) {
    cout << s << ":";
    for (int i = 0; i < b.size(); ++i) cout << " " << b[i];
    cout << endl;
}

// Pre: gamma.size() = epsilon.size()
// Post: retorna el consumo calculado como gamma*epsilon en decimal
int calcula_consumo(const Binario& gamma, const Binario& epsilon) {
    // Pasamos a decimal los numeros binarios
    int gammadec = 0;
    for (int i = 0; i < gamma.size(); ++i) {
        if (gamma[i] == '1') {
            int potencia = 1;
            for (int j = 0; j < gamma.size() - i - 1; ++j) {
                potencia *= 2;
            }
            gammadec += potencia;
        }
    }
    // Ahora calcularemos el numero maximo que se puede expresar en binario
    // y le restaremos el valor de gamma para obtener epsilon
    int total = 0;
    for (int i = 0; i < epsilon.size(); ++i) {
        int potencia = 1;
        for (int j = 0; j < epsilon.size() - i - 1; ++j) {
            potencia *= 2;
        }
        total += potencia;
    }
    // int epsilondec = total - gammadec;

    return gammadec * (total - gammadec);
}

// Pre: mat.size > 0; 0 <= j < mat[0].size()
// Post: retorna el bit más frecuente en la columna j de mat. En caso de empate retorna '0'.
char bit_mas_comun(const MatrizChar& mat, int j) {
    int count0 = 0, count1 = 0;
    for (int i = 0; i < mat.size(); ++i) {
        if (mat[i][j] == '0') ++count0;
        else ++count1;
    }

    if (count0 != count1) {
        if (count0 > count1) return '0';
        else return '1';
    }
    else return '0';
}

// Pre: mat.size > 0; gamma.size() == mat[0].size(); epsilon.size() == mat[0].size()
// Post: gamma y epsilon son el ratio gamma y epsilon de mat, respectivamente
void calcula_ratios(const MatrizChar& mat, Binario& gamma, Binario& epsilon) {
    for (int j = 0; j < mat[0].size(); ++j) {
        char bit = bit_mas_comun(mat, j);
        gamma[j] = bit;
        if (bit == '0') epsilon[j] = '1';
        else epsilon[j] = '0';
    }
}

int main() {
 int n, m;
    while (cin >> n >> m) {
        MatrizChar mat = leer_matriz(n, m);
        Binario gamma(m);
        Binario epsilon(m);
        calcula_ratios(mat, gamma, epsilon);
        escribir("Gamma", gamma);
        escribir("Epsilon", epsilon); 
        cout << "Consumo: " << calcula_consumo(gamma, epsilon) << endl << endl;
    }
}