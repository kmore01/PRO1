//programa que llegeix un natural i escriu la suma de les seves tres darreres xifres

#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    int a, b;
    a= n/10;
    b= a/10;
    cout << (n%10 + a%10 + b%10) << endl;

}