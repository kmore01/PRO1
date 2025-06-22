/* Program that prints the position of the maximum number */

#include <iostream>
#include <vector>

using namespace std;

// Function that saves numbers in a vector
vector<double> read_in_vector() {
    int size;
    cin >> size;
    vector<double> VNumbers(size);
    for (int i = 0; i < size; ++i) {
        cin >> VNumbers[i];
    }
    return VNumbers;
}

// Function that returns the position of the maximum number
int position_maximum(const vector<double>& v, int m) {
    int position = 0;
	double max_value = v[0];
	for (int i = 1; i <= m; ++i) {
		if (v[i] > max_value) {
			position = i;
			max_value = v[i];
		}
    }
    return position;
}

int main () {
    vector<double> numbers = read_in_vector();
    int limit;
    cin >> limit;
    cout << position_maximum(numbers, limit);
}