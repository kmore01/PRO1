#include <cmath>
#include <vector>

using namespace std;

// Pre: Let n be v.size(). Then, for each i in {0..n-2}, |v[i]-v[i+1]|<=2 holds.
//      In addition, there is exactly one i in {0..n-2} satisfying |v[i]-v[i+1]|=1.
// Post: The function returns this particular i in {0..n-2} satisfying |v[i]-v[i+1]|=1.
int positionDistance1(const vector<int> &v) {
  int n = int(v.size());
  int inf = 0;
  int sup = n-1;
  while (inf+1 < sup) {
    int med = (inf+sup)/2;
    if (v[med]%2 == v[0]%2) inf = med;
    else sup = med;
  }
  return inf;
}
