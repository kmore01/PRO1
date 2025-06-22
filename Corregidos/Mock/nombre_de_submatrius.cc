#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > Matrix;

void solve(Matrix &v) {
  int n = int(v.size());
  int m = int(v[0].size());
  int sol = 0;
  Matrix sq(n, vector<int> (m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i == 0 or j == 0 or v[i][j] != v[i][j-1] or v[i][j] != v[i-1][j] or v[i][j] != v[i-1][j-1]) {
        sq[i][j] = 1;
      }
	  else {
        sq[i][j] = 1 + min(sq[i-1][j-1], min(sq[i-1][j], sq[i][j-1]));
      }
      sol += sq[i][j];
    }
  }
  cout << sol << endl;
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    Matrix v(n, vector<int> (m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        char c;
        cin >> c;
        v[i][j] = c - '0';
      }
    }
    solve(v);
  }
}