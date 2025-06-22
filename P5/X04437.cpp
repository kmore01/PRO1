// program that calculates distance to the origen from the point (x,y)

#include <iostream>
#include <cmath>
using namespace std;

// function that calculates distance from the origen point
// Precondition: double
// Postcondition: double
double dist_or(double x, double y) {
    return sqrt((x * x) + (y * y));
}

int main () {
    double x, y;
    cin >> x >> y;
    cout << dist_or(x,y) << endl;
}