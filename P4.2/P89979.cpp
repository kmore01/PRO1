#include <iostream>
using namespace std;

int main() {
	string prev, next; // paraules amb lletres minuscules
	int num_paraules, resultat = 1; 
	bool creixent = false;
	while (not creixent and cin >> num_paraules) {
		creixent = true;
		cin >> prev;
		for (int i = 2; i <= num_paraules; ++i) {
			cin >> next;
			if (next < prev) creixent = false;
			prev = next;
		}
		if (creixent) cout << "La primera linia ordenada creixentment es la " << resultat << "." << endl;
		++resultat;
	}
	if (not creixent) cout << "No hi ha cap linia ordenada creixentment." << endl;
}
