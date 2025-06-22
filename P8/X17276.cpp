// program that returns if the four diagonals of an element increase or not

#include <iostream>
#include <vector>
using namespace std;
typedef vector< vector<int> > MatrixChar;

// function that saves elements in a matrix
vector< vector<int> > read_in_matrix(int rows, int columns) {
    vector< vector<int> > matrix(rows, vector<int>(columns));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

// function that returns if the fours diagonals are increasing
bool increasing_diagonal(const MatrixChar& a, int rows, int columns) {
    int row, column;
    cin >> row >> column;
    int elem = a[row][column], j, i, diagonal = 1;
    bool increasing = true;
    while (increasing and diagonal > 0) {
        j = column - 1;
        i = row - 1;
        while (increasing and i >= 0 and j >= 0) { // first diagonal
            if (a[i][j] <= elem) increasing = false;
            else elem = a[i][j];
            --i;
            --j;
        }
        elem = a[row][column];
        j = column - 1;
        i = row + 1;
        while (increasing and i < rows and j >= 0) { // second diagonal
            if (a[i][j] <= elem) increasing = false;
            else elem = a[i][j];
            ++i;
            --j;
        }
        elem = a[row][column];
        j = column + 1;
        i = row + 1;
        while (increasing and i < rows and j < columns) { // third diagonal
            if (a[i][j] <= elem) increasing = false;
            else elem = a[i][j];
            ++i;
            ++j;
        }
        elem = a[row][column];
        i = row - 1;
        j = column + 1;
        while (increasing and i >= 0 and j < columns) { // four diagonal
            if (a[i][j] <= elem) increasing = false;
            else elem = a[i][j];
            --i;
            ++j;
        }
        --diagonal;
    }
    return increasing;
}

int main () {
    int rows, columns;
    while (cin >> rows >> columns) {
        vector< vector<int> > matrix = read_in_matrix(rows, columns);
        if (increasing_diagonal(matrix, rows, columns)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}