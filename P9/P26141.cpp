/* program that reads a sequence of rational numbers and operations and
calculates the result */

#include <iostream>

using namespace std;

struct Rational {
    int num, den;
};

/* function that calculates the gcd of two numbers */
int gcd(int div, int den) { 
	if (den == 0) return div;
	else return gcd(den, div % den);

}

/* function that calculates the reduced rational */
/* Pre: d â‰  0 */
/* Post: */
Rational simplify(int n, int d) {
    Rational p;
    int divisor = gcd (n, d);
    p.num = n / divisor;
    p.den = d / divisor;
    if (p.den < 0) { /* we change the symbol */
        p.num = -p.num;
        p.den = -p.den;
    }
    return p;
}

Rational sum(Rational& r1, Rational& r2) {
    Rational add;
    add.den = r1.den * r2.den;
    add.num = r1.num * r2.den + r2.num * r1.den;
    return simplify(add.num, add.den);
}

Rational multiply(Rational& r1, Rational& r2) {
	Rational m;
	m.num = r1.num * r2.num;
	m.den = r1.den * r2.den;
	return simplify(m.num, m.den);
}

Rational divide(Rational& r1, Rational& r2) {
	Rational d;
	d.num = r1.num * r2.den;
	d.den = r1.den * r2.num;
	return simplify(d.num, d.den);
}

void print_rational(Rational& r) {
	if (r.num == 0) cout << 0 << endl;
	else if (r.den == 1) cout << r.num << endl;
	else cout << r.num << "/" << r.den << endl;
}

int main () {
    Rational n1, n2;
    cin >> n1.num >> n1.den;
    n1 = simplify(n1.num, n1.den);
    print_rational(n1);
    string operation;
    while (cin >> operation) {
        /* we will use n1 in order to be changing the fist rational */
        cin >> n2.num >> n2.den;
        if (operation == "add") {
            n1 = sum(n1, n2);
        }
        else if (operation == "substract") {
            n2.num = -n2.num;
            n1 = sum(n1, n2);
        }
        else if (operation == "multiply") {
            n1 = multiply(n1, n2);
        }
        else {
            n1 = divide(n1, n2);
        }
        print_rational(n1);
    }
}