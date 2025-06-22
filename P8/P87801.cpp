// program that calculates the maximum number of points achievable in a puzzle

#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<char> > MatrixChar;
typedef vector< vector<int> > MatrixInt;

// function that saves characters in a matrix
MatrixChar read_in_board(int rows, int columns) {
    MatrixChar matrix(rows, vector<char>(columns));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) cin >> matrix[i][j];
    }
    return matrix;
}

// function that saves integers in a matrix
MatrixInt read_in_board_values(int rows, int columns) {
    MatrixInt matrix(rows, vector<int>(columns));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) cin >> matrix[i][j];
    }
    return matrix;
}

// function that saves words in a vector
vector<string> read_sequences(int size) {
    vector<string> V(size);
    for (int i = 0; i < size; ++i) cin >> V[i]; 
    return V;
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

bool alphabet_soup_(const MatrixChar& aux, vector<string> words) {
    bool hola = true;
	for (int k = 0; k < words.size(); ++k) {
		int i  = 0;
		string s1 = words[k];
		while (i < aux.size()) {
			int j = 0;
			while (j < aux[0].size()) {
				if (not found(aux, s1, i, j, 0, 1)) return false;
				if (not found(aux, s1, i, j, 1, 0)) return false;
				++j;
			}
			++i;
		}
	}
    return hola;
}

int main () {
    int rows, columns;
    while (cin >> rows >> columns) {
        MatrixChar board = read_in_board(rows, columns);
        MatrixInt board_values = read_in_board_values(rows, columns);
        int num_words;
        cin >> num_words;
        vector<string> words = read_sequences(num_words);
        cout << alphabet_soup_(board, words) << endl;
    }
}