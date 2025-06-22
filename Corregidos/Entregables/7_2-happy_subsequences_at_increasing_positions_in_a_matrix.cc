// Entregable: PRO1 2023-2024 Q1 D7_T1_online

#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<int> VI;
typedef vector<VI> VVI;

// Pre: -
// Creates and fills a matrix
VVC read_matrix(int n, int m) {
    VVC M(n, VC(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)  cin >> M[i][j];
    }

    return M;
}

// Pre: M.size(), M[i].size() > 0; i < M.size(); j < M[i].size()
// Returns value of M in (i, j) if the position exists. If not, retuns 0
int get_value(const VVI& M, int i, int j) {
    if (i < 0 or j < 0)  return 0;
    return M[i][j];
}

// Pre: M_col.size() = M.size(), M_col[0].size() = M[0].size()
// M_col[i][j] counts ':' in M[row][col] with 0 <= row <= i, 0 <= col <= j
void count_colons(VVI& M_col, const VVC& M) {
    for (int i = 0; i < M_col.size(); ++i) {
        for (int j = 0; j < M_col[0].size(); ++j) {
            // number of ':' in top-left submatrix with no repetitions:
            M_col[i][j] = get_value(M_col, i-1, j) + get_value(M_col, i, j-1) - get_value(M_col, i-1, j-1);
            if (M[i][j] == ':') ++M_col[i][j];
        }
    }
}

// Pre: M_hyp.size() = M_col.size() = M.size(), M_hyp[0].size() = M_col[0].size() = M[0].size()
// M_hyp[i][j] counts faces ":-" with '-' in M[row][col] with 0 <= row <= i, 0 <= col <= j
void count_hyphens(VVI& M_hyp, const VVI& M_col, const VVC& M) {
    for (int i = 0; i < M_hyp.size(); ++i) {
        for (int j = 0; j < M_hyp[0].size(); ++j) {
            // number of '-' being part of ":-" in top-left submatrix with no repetitions:
            M_hyp[i][j] = get_value(M_hyp, i-1, j) + get_value(M_hyp, i, j-1) - get_value(M_hyp, i-1, j-1);
            if (M[i][j] == '-')  M_hyp[i][j] += get_value(M_col, i-1, j-1);
        }
    }
}

// Pre: M_par.size() = M_hyp.size() = M.size(), M_par[0].size() = M_hyp[0].size() = M[0].size()
// M_par[i][j] counts faces ":-)" with ')' in M[row][col] with 0 <= row <= i, 0 <= col <= j
void count_parenthesis(VVI& M_par, const VVI& M_hyp, const VVC& M) {
    for (int i = 0; i < M_par.size(); ++i) {
        for (int j = 0; j < M_par[0].size(); ++j) {
            // number of ')' being part of ":-)" in top-left submatrix with no repetitions:
            M_par[i][j] = get_value(M_par, i-1, j) + get_value(M_par, i, j-1) - get_value(M_par, i-1, j-1);
            if (M[i][j] == ')')  M_par[i][j] += get_value(M_hyp, i-1, j-1);
        }
    }
}

// Pre: -
// Returns the number of happy faces in incremental positions in M
int count_happy_faces(const VVC& M) {
    int n = M.size();
    int m = M[0].size();
    VVI M_col, M_hyp, M_par;
    M_col = M_hyp = M_par = VVI(n, VI(m, 0));

    count_colons(M_col, M);
    count_hyphens(M_hyp, M_col, M);
    count_parenthesis(M_par, M_hyp, M);
    
    return M_par[n-1][m-1];
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        VVC M = read_matrix(n, m);
        cout << count_happy_faces(M) << endl;
    }
}