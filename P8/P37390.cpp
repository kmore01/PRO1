// program that calculates the products of square matrices

#include <iostream>
#include <vector>
using namespace std;
typedef vector< vector<int> > MatrixChar;

// function that saves elements in a matrix
vector< vector<int> > read_in_matrix() {
    int size;
    cin >> size;
    vector< vector<int> > matrix(size, vector<int>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

// function that returns the product of square matrices
MatrixChar product(const MatrixChar& a, const MatrixChar& b) {
    int rows_columns_a = a.size();
    int rows_columns_b = b[0].size();
    MatrixChar c(rows_columns_a, vector<int>(rows_columns_b)); // result matrix
    for (int j = 0; j < rows_columns_b; ++j) {
        for (int k = 0; k < rows_columns_a; ++k) {
            for (int i = 0; i < rows_columns_a; ++i) {
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
    int rows_columns = matrix3.size();
    for (int i = 0; i < rows_columns; ++i) {
        for (int j = 0; j < rows_columns; ++j) {
            cout << matrix3[i][j] << ' ';
        }
        cout << endl;
    }
}