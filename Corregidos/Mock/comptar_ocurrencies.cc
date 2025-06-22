#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > Matrix;

int main() {
  int n, m;
  while (cin >> n >> m) {
    Matrix v(n, vector<int> (m));
    Matrix fil2d(n, vector<int> (10, 0));
    Matrix col2d(m, vector<int> (10, 0));

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        char c;
        cin >> c;
	    int d = c - '0';
	    v[i][j] = d;
	    ++fil2d[i][d];
	    ++col2d[j][d];
      }
    }

    // AQUIIIIIIII
	
    Matrix sol(n, vector<int> (m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int d = v[i][j];
        sol[i][j] = (fil2d[i][d] + col2d[j][d]) % 10;
      }
    }
	
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j)  cout << sol[i][j];
      cout << endl;
    }
    cout << endl;
  }
}
