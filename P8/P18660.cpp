// program that solves word searches

#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<char> > MatrixChar;

// function that saves words in a vector
vector<string> read_words(int size) {
    vector<string> V(size);
    for (int i = 0; i < size; ++i) cin >> V[i]; 
    return V;
}

// function that saves characters in a matrix
MatrixChar read_matrix_soup(int rows, int columns) {
    MatrixChar matrix(rows, vector<char>(columns));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) cin >> matrix[i][j];
    }
    return matrix;
}

// function that converts a lowercase character to uppercase
void uppercase(MatrixChar& soup, int l, int i, int j, int ini_i, int ini_j) {
    	int k = 0;
	    while (k < l) {
		    if (soup[i][j] >= 'a' and soup[i][j] <= 'z') soup[i][j] = char(int(soup[i][j])-int('a') + int('A'));
		    i += ini_i;
		    j += ini_j;
		    ++k;
	    }
}

// function that returns if the word is in the matrix soup
bool found(const MatrixChar& aux, string word, int i, int j, int ini_i, int ini_j) {
    int k = 0;
    while (i < aux.size() and j < aux[0].size() and k < word.size()) {
        if (word[k] != aux[i][j]) return false;
        i += ini_i;
        j += ini_j;
        ++k;
    }
    return k == word.size();
}

void alphabet_soup_(const MatrixChar& aux, MatrixChar& sopa, vector<string> words) {
	for (int k = 0; k < words.size(); ++k) {
		int i  = 0;
		string s1 = words[k];
		while (i < sopa.size()) {
			int j = 0;
			while (j < sopa[0].size()) {
				if (s1[0] == aux[i][j]) {
					if (found(aux, s1, i, j, 0, 1)) uppercase(sopa, s1.size(), i, j, 0, 1);
					if (found(aux, s1, i, j, 1, 0)) uppercase(sopa, s1.size(), i, j, 1, 0);
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
        vector<string> words = read_words(num_words); // words
        MatrixChar alphabet_soup = read_matrix_soup(rows, columns); // alphabet soup
        MatrixChar aux = alphabet_soup;
        alphabet_soup_(aux, alphabet_soup, words);
        // print the solution
        for (int i = 0; i < rows; ++i) {
            cout << alphabet_soup[i][0];
            for (int j = 1; j < columns; ++j) {
                cout << ' ' << alphabet_soup[i][j];
            }
            cout << endl;
        }
    }
}