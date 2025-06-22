// program that calculates the number of rectangular growings

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> Column;
typedef vector<Column> MatrizChar;

// function that saves natural numbers in a matrix
MatrizChar read_in_matrix(int rows, int columns) {
    MatrizChar vegetable_matrix(rows, Column(columns));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cin >> vegetable_matrix[i][j];
        }
    }
    return vegetable_matrix;
}

// procedure that turns into 0 a rectangular growing
void complete_zero(MatrizChar &A, int row, int column) {
    int numrow = A.size();
    int numcol = A[0].size();
    int i = row;
    int j = column;
    while (i < numrow and A[i][j] != 0) {
        while (j < numcol and A[i][j] != 0) {
            if (A[i][j] != 0) {
                A[i][j] = 0;
                ++j;
            }
        }
        j = column;
        ++i;
    }
}

// procedure that counts the number of rectangular growings
void numbers_growing(MatrizChar &M) {
    int numrow = M.size();
    int numcol = M[0].size();
    int count = 0;
    for (int i = 0; i < numrow; ++i) {
        for (int j = 0; j < numcol; ++j) {
            if (M[i][j] != 0) {
                complete_zero(M, i, j);
                ++count;
            }
        }
    }
    cout << count << endl;
}

int main () {
    int numrow, numcol;
    while (cin >> numrow >> numcol) {
        MatrizChar M = read_in_matrix(numrow, numcol);
        numbers_growing(M);
    }
}