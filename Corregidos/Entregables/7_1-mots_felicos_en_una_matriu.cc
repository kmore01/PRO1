// Entregable: PRO1 2023-2024 Q1 D7_T1_online

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char> > VVC;

bool check_face_1(const VVC& M, int i, int j) {
    return j >= 2 and M[i][j-2] == ':' and M[i][j-1] == '-' and M[i][j] == ')';
}

bool check_face_2(const VVC& M, int i, int j) {
    return j >= 2 and M[i][j-2] == '(' and M[i][j-1] == '-' and M[i][j] == ':';
}

bool check_face_3(const VVC& M, int i, int j) {
    return i >= 2 and M[i-2][j] == '"' and M[i-1][j] == '|' and M[i][j] == 'v';
}

bool check_face_4(const VVC& M, int i, int j) {
    return i >= 2 and M[i-2][j] == '^' and M[i-1][j] == '|' and M[i][j] == '"';
}

int count_faces(int n, int m) {
    int num_faces = 0;

    VVC M(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> M[i][j];
            num_faces += check_face_1(M, i, j);
            num_faces += check_face_2(M, i, j);
            num_faces += check_face_3(M, i, j);
            num_faces += check_face_4(M, i, j);
        }
    }

    return num_faces;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        cout << count_faces(n, m) << endl;
    }
}