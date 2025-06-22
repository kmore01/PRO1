/* program that calculates the euclidean distance between two points a and b */

#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

/* function that returns the euclidean distance */
double dist(const Point& a, const Point& b) {
    return sqrt(((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y)));
    /* a.x is the distance on the x-axis of the point a */
}

int main () {
    Point a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    cout << dist(a, b) << endl;
}