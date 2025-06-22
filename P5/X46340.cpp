// program that prints the sum of the minimum and the maximum of three integers

#include <iostream>
using namespace std;

// function that calculates sum of min and max
// Precondition: 0 < x, y, z < 10^9
// Postcondition: integer
int sum_min_max(int x, int y, int z) {
    int max = x, min = x;
    if (y > max) max = y;
    if (z > max) max = z;
    if (y < min) min = y;
    if (z < min) min = z;
    return max + min;
}

int main () {
    int x, y, z;
    cin >> x >> y >> z;
    cout << sum_min_max(x, y, z) << endl;
}