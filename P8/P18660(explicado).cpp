// program that solves word searches

#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<char> > MatrixChar;

// funcion que guarda las palabras en un vector
vector<string> read_words(int size) {
    vector<string> V(size);
    for (int i = 0; i < size; ++i) cin >> V[i]; 
    return V;
}

// funcion que guarda los caracteres en una matriz
MatrixChar read_matrix_soup(int rows, int columns) {
    MatrixChar matrix(rows, vector<char>(columns));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) cin >> matrix[i][j];
    }
    return matrix;
}

// funcion que convierte las letras minusculas en mayusculas
void uppercase(MatrixChar& soup, int l, int i, int j, int ini_i, int ini_j) {
    	int k = 0;
        // l es el tamaño de la palabra
	    while (k < l) {
            // si esa letra no es mayuscula la convertimos (hay casos donde una misma letra pertenece a dos palabras)
		    if (soup[i][j] >= 'a' and soup[i][j] <= 'z') soup[i][j] = char(int(soup[i][j])-int('a') + int('A'));
            // esto se hace para avanzar de posiciones (en horizontal solo se incrementa la i, en vertical solo se incrementa la j y en diagonal las dos)
		    i += ini_i;
		    j += ini_j;
		    ++k;
	    }
}

// funcion que devuelve en booleano si la palabra està en la sopa de letras
bool found(const MatrixChar& aux, string word, int i, int j, int ini_i, int ini_j) {
    int k = 0;
    while (i < aux.size() and j < aux[0].size() and k < word.size()) {
        // si ya empezamos y no la encontramos devolvemos falso
        if (word[k] != aux[i][j]) return false;
        // esto se hace para avanzar de posiciones (en horizontal solo se incrementa la i, en vertical solo se incrementa la j y en diagonal las dos)
        i += ini_i;
        j += ini_j;
        ++k;
    }
    // si k == word.size() significa que hemos encontrado la palabra porque no hemos encontrado ninguna posicion para la cual los caracteres no sean iguales (porque esto devolveria directamente falso)
    return k == word.size();
}

// funcion que utiliza las otras funciones previamente creadas para encontrar la matriz solucion
void alphabet_soup_(const MatrixChar& aux, MatrixChar& sopa, vector<string> words) {
	for (int k = 0; k < words.size(); ++k) {
		int i  = 0;
		string s1 = words[k];
		while (i < sopa.size()) {
			int j = 0;
			while (j < sopa[0].size()) {
                // si encontramso que una letra de la matrix es igual a la letra de la palabra llamamos a found para comprobar que realmente esa letra despues tiene todos los caracteres necesarios para formar la palabra, si es asi, la convertimos en mayuscula (en la funcion para convertir en mayuscula ya hay el bucle para convertirla, asi que no hay problema)
				if (s1[0] == aux[i][j]) {
                    // la i = 0, j = 1 te indica que buscamos las VERTICALES (se iran incrementando)
					if (found(aux, s1, i, j, 0, 1)) uppercase(sopa, s1.size(), i, j, 0, 1);
                    // la i = 1, j = 0 te indica que buscamos las HORIZONTALES (se iran incrementando)
					if (found(aux, s1, i, j, 1, 0)) uppercase(sopa, s1.size(), i, j, 1, 0);
                    // la i = 1, j = 1 te indica que buscamos las DIAGONALES (se iran incrementando)
					if (found(aux, s1, i, j, 1, 1)) uppercase(sopa, s1.size(), i, j, 1, 1);
				}
				++j;
			}
			++i;
		}
	}
}


int main () {
    int num_words, rows, columns, position = 0;
    while (cin >> num_words >> rows >> columns) {
        if (position != 0) cout << endl;
        position = 1;
        vector<string> words = read_words(num_words); // palabras
        MatrixChar alphabet_soup = read_matrix_soup(rows, columns); // sopa de letras
        MatrixChar aux = alphabet_soup;
        alphabet_soup_(aux, alphabet_soup, words);
        // imprimimos la solucion (cuidado con los espacios)
        for (int i = 0; i < rows; ++i) {
            cout << alphabet_soup[i][0];
            for (int j = 1; j < columns; ++j) {
                cout << ' ' << alphabet_soup[i][j];
            }
            cout << endl;
        }
    }
}