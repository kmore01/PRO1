// program that counts happy subsequences

#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<int> > MatrixInt;
typedef vector< vector<char> > MatrixChar;

// function that saves characters in a matrix
MatrixChar read_matrix_soup(int rows, int columns) {
    vector< vector<char> > matrix(rows, vector<char>(columns));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

// function that returns the vertical, horitzontal and diagonal values
int val(const MatrixInt &matrix, int i, int j){
	if (i < 0 or j < 0) return 0;
	else return matrix[i][j];
}	

// function that calculates the happy faces
int HappySubsequences(const MatrixChar &matrix, int row, int column){
	MatrixInt C1Count(row, vector<int>(column,0)); //':'
	MatrixInt C2C1Count(row, vector<int>(column,0)); //'-'
	MatrixInt C3C2C1Count(row, vector<int>(column,0)); //')'
	
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			char elem = matrix[i][j];
			// first character
			C1Count[i][j] = val(C1Count, i - 1, j) + val(C1Count, i, j - 1) - val(C1Count, i - 1, j - 1);
			if (elem == ':') ++C1Count[i][j];

			// second character
			C2C1Count[i][j] = val(C2C1Count, i-1, j) + val(C2C1Count, i, j - 1) - val(C2C1Count, i-1, j-1);
			if(elem == '-') C2C1Count[i][j] += val(C1Count, i - 1, j - 1);

			// third character
			C3C2C1Count[i][j] = val(C3C2C1Count, i - 1, j) + val(C3C2C1Count, i, j - 1) - val(C3C2C1Count, i - 1, j - 1);
			if(elem == ')')C3C2C1Count[i][j] += val(C2C1Count, i - 1, j - 1);
		}
	}
	return C3C2C1Count[row - 1][column - 1];
}

int main(){
	int row, column;
	while (cin >> row >> column) {
		MatrixChar matrix1 = read_matrix_soup(row, column);
		cout << HappySubsequences(matrix1, row, column) << endl;
	}
}
