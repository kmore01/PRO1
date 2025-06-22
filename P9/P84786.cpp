/* program that calculates the movement of a point according to another point, the scales of a circle, the movement of a circle according to a point and if a point is inside a circle or not */

#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

struct Circle {
    Point center;
    double radius;
};

/* procedure that moves the point p1 according to the point p2 */
void move(Point& p1, const Point& p2) {
    p1.x += p2.x;
    p1.y += p2.y;
}

/* procedure that scales the circle c proportionately to the real strictly
positive sca */
void scale(Circle& c, double sca) {
    c.radius *= sca;
}

/* procedure that moves the circle c according to the coordinates p */
void move(Circle& c, const Point& p) {
    move(c.center, p);
}

/* function that prints if a point p is inside a circle c */
bool is_inside(const Point& p, const Circle& c) {
    /* we calculate the distance from the two points */
    return sqrt((p.x-c.center.x) * (p.x-c.center.x)+(p.y-c.center.y) * (p.y-c.center.y)) < c.radius;
}

int main () {
    Point position;
    cin >> position.x >> position.y;
    Circle c;
    cin >> c.center.x >> c.center.y >> c.radius;
    double scal;
    cin >> scal;
    
    scale(c, scal);
    cout << c.radius << endl;

    move(c, position);
    cout << c.center.x << ' ' << c.center.y << endl;
    
    cout << is_inside(position, c) << endl;
}