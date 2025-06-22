// program that calculates the number of happy subwords in each matrices

#include <iostream>
#include <vector>
using namespace std;
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

// function that calculates the happy subsequences
int numberSubsequences(const MatrixChar &a) {
    int cont = 0;
    int rows = a.size();
    int columns = a[0].size();
    for (int i = 0; i < rows; ++i) { // horizontal faces
        for (int j = 0; j < columns; ++j) {
            if (j + 2 < columns) {
                if (a[i][j] == ':' and a[i][j + 1] == '-' and a[i][j + 2] == ')') ++cont;
                else if (a[i][j] == '(' and a[i][j + 1] == '-' and a[i][j + 2] == ':') ++cont;
            }
        }
    }
    for (int i = 0; i < rows; ++i) { // vertcial faces
        for (int j = 0; j < columns; ++j) {
            if (i + 2 < rows) {
                if (a[i][j] == '"' and a[i + 1][j] == '|' and a[i + 2][j] == 'v') ++cont;
                else if (a[i][j] == '^' and a[i + 1][j] == '|' and a[i + 2][j] == '"') ++cont;
            }
        }
    }
    return cont;
}

int main () {
    int rows, columns;
    while (cin >> rows >> columns) {
        MatrixChar matrix1 = read_matrix_soup(rows, columns);
        cout << numberSubsequences(matrix1) << endl;
    }
}