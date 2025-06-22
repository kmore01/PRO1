// Entregable: PRO1 2023-2024 Q1 D7_T8_online
// Optimitzacio: # operacions sum(mul()): 2*k*n --> 3*n + k

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Point {
    double x, y, z;
};

struct Particle {
    Point p, v;
    double m;
};

// Pre:
// Post: returns the sum of p1 and p2
Point sum(Point p1, Point p2) {
    Point p;
    p.x = p1.x + p2.x;
    p.y = p1.y + p2.y;
    p.z = p1.z + p2.z;
    return p;
}

// Pre:
// Post: returns p times a
Point mul(double a, Point p) {
    Point p_mul;
    p_mul.x = p.x * a;
    p_mul.y = p.y * a;
    p_mul.z = p.z * a;
    return p_mul;
}

void printDouble(double d) {
    if (abs(d) < 1e-7)  cout << 0.0;
    else  cout << d;
}

void printPoint(const Point& p) {
    printDouble(p.x);
    cout << ' ';
    printDouble(p.y);
    cout << ' ';
    printDouble(p.z);
    cout << '\n';
}

// Pre:
// Reads k times. At each, the centre of mass is computed. Returns the total time
int treat_times(int n, int k, vector<Particle>& particles) {
    // mass_centre = mass_centre_p + t·mass_centre_v
    // computation of position and speed of the centre of mass:
    Particle mass_centre;
    mass_centre.p.x = mass_centre.p.y = mass_centre.p.z = 0;
    mass_centre.v.x = mass_centre.v.y = mass_centre.v.z = 0;
    mass_centre.m = 0;

    for (int p_i = 0; p_i < n; ++p_i) {
        mass_centre.p = sum(mass_centre.p, mul(particles[p_i].m, particles[p_i].p));
        mass_centre.v = sum(mass_centre.v, mul(particles[p_i].m, particles[p_i].v));
        mass_centre.m += particles[p_i].m;
    }
    mass_centre.p = mul(1.0/mass_centre.m, mass_centre.p);
    mass_centre.v = mul(1.0/mass_centre.m, mass_centre.v);

    int total_t = 0;
    for (int t_i = 0; t_i < k; ++t_i) { // iteration through times
        int t;
        cin >> t;
        total_t += t;
        Point mass_centre_i = sum(mass_centre.p, mul(total_t, mass_centre.v));
        printPoint(mass_centre_i);
    }

    return total_t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);    
    cout.setf(ios::fixed);
    cout.precision(5);

    int n, k;
    while (cin >> n >> k) {
        vector<Particle> particles(n);
        for (int p_i = 0; p_i < n; ++p_i) {
            cin >> particles[p_i].p.x >> particles[p_i].p.y >> particles[p_i].p.z;
            cin >> particles[p_i].v.x >> particles[p_i].v.y >> particles[p_i].v.z;
            cin >> particles[p_i].m;
        }

        int time = treat_times(n, k, particles); // sum of times

        for (int p_i = 0; p_i < n; ++p_i) {
            Point particle = sum(particles[p_i].p, mul(time, particles[p_i].v)); // final position
            printPoint(particle);
        }
        cout << '\n';
    }
}
