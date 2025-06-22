// program that calculates the biggest difference

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > MatrizChar;

// function that calculates maximum and minimum of a matrix
void min_max(const MatrizChar& mat, int& minimum, int& maximum) {
    int row = mat.size(), column = mat[0].size();
    minimum = maximum = mat[0][0];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if (mat[i][j] < minimum) minimum = mat[i][j];
            else if (mat[i][j] > maximum) maximum = mat[i][j];
        }
    }
}

// function that saves integers in a matrix
MatrizChar read_in_matrix(int rows, int columns) {
    MatrizChar matrix(rows, vector<int>(columns));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) cin >> matrix[i][j];
    }
    return matrix;
}

int main () {
    int rows, columns;
    int minimum, maximum, difference = -1, count = 0, position = 0;
    minimum = maximum = 0;
    while (cin >> rows >> columns) {
        MatrizChar matrix = read_in_matrix(rows, columns);
        min_max(matrix, minimum, maximum);
        ++count;        
        if (maximum - minimum > difference) {
            difference = maximum - minimum;
            position = count;
        }
    }
    cout << "la diferencia maxima es " << difference << endl;
    cout << "la primera matriu amb aquesta diferencia es la " << position << endl;
}