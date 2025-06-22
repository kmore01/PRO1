/* Programa que calcula el nombre d'alumnes que tenen mes nota que la mitjana */

#include <iostream>
#include <vector>

using namespace std;

struct Assignatura {
    string nom;                 // Nom de l’assignatura
    double nota;                // Entre 0 i 10, -1 indica NP
};

struct Alumne {
    string nom;                 // Nom de l’alumne
    int dni;                    // DNI de l’alumne
    vector<Assignatura> ass;    // Llista d’assignatures de l’alumne
};

// Pre: No hi ha alumnes repetits. A la llista d’assignatures de cada alumne no
// hi ha assignatures repetides.
// Funcio que busca i retorna la nota que l’alumne |dni| ha obtingut a
// l’assignatura |nom|
double nota(const vector<Alumne> &alums, int dni, string nom) {
    int size_alumns = alums.size(), nota = - 1;

    for (int i = 0; i < size_alumns; ++i) {
        if (alums[i].dni == dni) {
            for (int j = 0; j < alums[i].ass.size(); ++j) {
                if (alums[i].ass[j].nom == nom and alums[i].ass[j].nota >= 0) return alums[i].ass[j].nota;
            }
        }
    }

    return nota;
}

// Pre: No hi ha alumnes repetits. A la llista d’assignatures de cada alumne no
// hi ha assignatures repetides.
// Funcio que calcula i retorna la nota mitjana de les assignatures del vector
// |ass|
double mitjana(const vector<Assignatura> &ass) {
    int size = ass.size(), cont = 0;
    double mitjana = 0;
    for (int i = 0; i < size; ++i) {
        if (ass[i].nota >= 0) {
            mitjana += ass[i].nota;
            ++cont;
        }
    }
    // DUDA: Si todos son NP?
    return mitjana / cont;
}

// Pre: No hi ha alumnes repetits. A la llista d’assignatures de cada alumne no
// hi ha assignatures repetides.
// Porcediment que compta i deixa en el paràmetre de sortida |com| el nombre
// d’alumnes del vector |alums| que tenen una nota mitjana estrictament
// superior a la nota que l’alumne |dni| ha obtingut a l’assignatura |nom|
void compta(const vector<Alumne> &alums, int dni, string nom, int &com) {
    int size = alums.size();
    com = 0;
    for (int i = 0; i < size; ++i) {
        if (mitjana(alums[i].ass) > nota(alums, dni, nom)) ++com;
    }
}

// MAIN TE LO DA YA EL ENUNCIADO
int main() {
	int n;
	cin >> n;
	vector <Alumne>v(n);
	int j = 0;
	while (n--) {
		cin >> v[j].nom >> v[j].dni;
		int ns;
		cin >> ns;
		int i = 0;
		vector <Assignatura>vs(ns);
		while (i < ns) {
			cin >> vs[i].nom >> vs[i].nota;
			++i;
		}
		v[j].ass = vs;
		++j;
	}
	int i;
	string s;
	while (cin >> i >> s) {
		int c;
		compta(v, i, s, c);
		cout << c << endl;
	}
}