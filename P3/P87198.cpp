// programa que escriu un octàgon

#include <iostream>
using namespace std;

int main () {
  int n; // natural ≥ 2
  while (cin >> n) {
    int aux = n;
    // PRIMERA PART DEL ROMBE
    for (int i = 0; i < n - 1; ++i) {
      for (int j = 1 + i; j < n; ++j) { // espais descendents
        cout << ' ';
      }
      for (int j = 0; j < aux; ++j) { // X ascendents
        cout << 'X';
      }
      cout << endl;
      aux += 2;
    }
    // SEGONA PART DEL ROMBE
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n + ((n - 1) * 2); ++j) { // totes X 
        cout << 'X';
      }
      cout << endl;
    }
    // TERCERA PART DEL ROMBE
    int aux2 = 0;
    for (int i = 0; i < n - 1; ++i) {
      for (int j = n + 1 + i; j > n; --j) { // espais ascendets
          cout << ' ';
      }
      for (int j = aux2; j < n + ((n - 2) * 2); ++j) { // X descendents
        cout << 'X';
      }
      cout << endl;
      aux2 += 2;
    }
    cout << endl;
  }
}