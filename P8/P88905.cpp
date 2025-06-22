// program that calculates the products of matrices

#include <iostream>
#include <vector>
using namespace std;
typedef vector< vector<int> > MatrixChar;

// function that saves elements in a matrix
vector< vector<int> > read_in_matrix() {
    int rows, columns;
    cin >> rows >> columns;
    vector< vector<int> > matrix(rows, vector<int>(columns));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

// function that returns the product of matrices
MatrixChar product(const MatrixChar& a, const MatrixChar& b) {
    int rows_a = a.size();
    int columns_a = a[0].size();
    int columns_b = b[0].size();
    MatrixChar c(rows_a, vector<int>(columns_b)); // result matrix
    for (int j = 0; j < columns_b; ++j) {
        for (int k = 0; k < columns_a; ++k) {
            for (int i = 0; i < rows_a; ++i) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

int main () {
    vector< vector<int> > matrix1 = read_in_matrix();
    vector< vector<int> > matrix2 = read_in_matrix();
    vector< vector<int> > matrix3 = product(matrix1, matrix2);
    int rows = matrix3.size();
    int columns = matrix3[0].size();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << matrix3[i][j] << ' ';
        }
        cout << endl;
    }
}