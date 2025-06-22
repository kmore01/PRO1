/* program that calculates the simplified rational and if the denominator is negative change its sign of both denominator and numerator */

#include <iostream>

using namespace std;

struct Rational {
    int num, den;
};

/* function that calculates the gcd of two numbers */
int gcd(int div, int den) { 
    while (den != 0) {
        int r = div % den;
        div = den;
        den = r;
    }
    return div; 
}

/* function that calculates the reduced rational */
/* Pre: d ≠ 0 */
/* Post: */
Rational rational(int n, int d) {
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

int main () {
    int num, den;
    cin >> num >> den;
    Rational result = rational(num, den);
    cout << result.num << '/' << result.den << endl;
}