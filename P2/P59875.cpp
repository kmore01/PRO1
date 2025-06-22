// programa que escriu els números entre altres dos números

#include <iostream>
using namespace std;

int main () {
    int num1, num2;
    cin >> num1 >> num2;
    int max, min;
    if (num1 >= num2) { // busquem el número més gran i el més petit
        max = num1;
        min = num2;
    }
    else {
        max = num2;
        min = num1;
    }
    for (int i = max; i >= min; --i) {
        cout << i << endl;
    }
}