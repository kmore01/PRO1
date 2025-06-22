#include <iostream>

using namespace std;

void generate(int n) {
  cout << n;
  if (n == 0) return;
  for (int i = 0; i < n; i++) {
    generate(n-1);
    cout << n;
  }
}

int main() {
  int n;
  while (cin >> n) {
    generate(n);
    cout << endl;
  }
}
