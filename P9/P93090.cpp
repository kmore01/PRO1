/* program that calcuates the sum of fractions*/

#include <iostream>

using namespace std;

struct Fraction {
    int num, den;   // always strictly positive
};

Fraction addition(const Fraction& x, const Fraction& y) {
    Fraction result;
    result.num = x.num * y.den + x.den * y.num;
    result.den = x.den * y.den;
    return result;
}

/*function that calculates the gcd*/
int gcd(int a, int b) {
	while (a != b) {
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}

/*procedure that reduces a fraction*/
void reduce(Fraction& a) {
	if (a.den > 1) {
		int e = gcd(a.num, a.den);
		a.num /= e;
		a.den /= e;
	}
}

int main () {
    Fraction number, operand;
    operand.num = 0;
    operand.den = 1;
    char oper;
    bool found = true;
    while (found) {
        cin >> number.num >> oper >> number.den >> oper;
        if (oper == '=') {
            found = false;
        }
        operand = addition(number, operand);
        reduce(operand);
    }
    cout << operand.num << '/' << operand.den << endl;
}