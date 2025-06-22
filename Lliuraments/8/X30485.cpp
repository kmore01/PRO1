/* program that calculates the mass center and the new position of particles
after a certain time*/

#include <iostream>
#include <vector>

using namespace std;

struct Point {
    double x, y, z;
};

struct Particle {
    Point p, v;
    double m;
};

/* function that calculates the sum of the position of two particles */
Point sum(Point p1, Point p2) {
    Point result;
    result.x = p1.x + p2.x;
    result.y = p1.y + p2.y;
    result.z = p1.z + p2.z;
    return result;
}

/* function that calculates the position of a particles after a time */
Point mul(double a, Point p) {
    Point result;
    result.x = a * p.x;
    result.y = a * p.y;
    result.z = a * p.z;
    return result;
}

/* procedure that prints double numbers */
void printDouble(double d) {
    if (abs(d) < 1e-7)
        cout << 0.0;
    else
        cout << d;
}

/* function that calculates position multiplied by mass of the center of mass */
Point CenterOfMass1(const vector<Particle>& particles) {
    int size = particles.size();
    Point result = {0, 0, 0};

    for (int i = 0; i < size; ++i) {
        result = sum(result, mul(particles[i].m, particles[i].p));
    }
    return result;
}

/* function that calculates velocity multiplied by mass of the center of mass */
Point CenterOfMass2(const vector<Particle>& particles) {
    int size = particles.size();
    Point result = {0, 0, 0};

    for (int i = 0; i < size; ++i) {
        result = sum(result, mul(particles[i].m, particles[i].v));
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(5);

    int num_particles, num_times;
    while (cin >> num_particles >> num_times) {
        vector<Particle> particles(num_particles);
        int total_mass = 0;

        for (int i = 0; i < num_particles; ++i) {
            cin >> particles[i].p.x >> particles[i].p.y >> particles[i].p.z;
            cin >> particles[i].v.x >> particles[i].v.y >> particles[i].v.z;
            cin >> particles[i].m;
            total_mass += particles[i].m;
        }

        /* we calculate a part of the center of mass without time */
        Point centerOfMass = CenterOfMass1(particles);
        Point centerOfMass2 = CenterOfMass2(particles);

        int total_time = 0;
        for (int i = 0; i < num_times; ++i) {
            int time;
            cin >> time;
            total_time += time;

            printDouble(((centerOfMass2.x * total_time) + centerOfMass.x) / double(total_mass));
            cout << ' ';
            printDouble(((centerOfMass2.y * total_time) + centerOfMass.y) / double(total_mass));
            cout << ' ';
            printDouble(((centerOfMass2.z * total_time) + centerOfMass.z) / double(total_mass));
            cout << '\n';
        }

        for (int i = 0; i < num_particles; ++i) {
            Point finalPos = sum(particles[i].p, mul(total_time, particles[i].v));

            printDouble(finalPos.x);
            cout << ' ';
            printDouble(finalPos.y);
            cout << ' ';
            printDouble(finalPos.z);
            cout << '\n';
        }
        cout << '\n';
    }
}
