/* program that creates teams based on their level of programming, their
nacionality and their lexicographic order */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Programmer {
    string name;
    int level;
};

// Funcion que guarda el nombre y el nivel de programadores
vector<Programmer> read_in_vector(int size) {
    vector<Programmer> V(size);
    for (int i = 0; i < size; ++i) {
        cin >> V[i].name >> V[i].level;
    }
    return V;
}

// Funcion que une y ordena dos vectores segun diferentes criterios
vector<Programmer> fusion(const vector<Programmer> &A, const vector<Programmer> &B, int c) {
    vector<Programmer> C;
    int i = 0, j = 0;
    int countIsrael = 0, countPalestine = 0, minLevel = 0;

    while (i < A.size() and j < B.size()) {
        // Primer criterio: Nivel de programación
        if (A[i].level > B[j].level and A[i].level >= minLevel) {
            C.push_back(A[i]);
            ++i;
            ++countIsrael;
            if (minLevel > A[i].level) minLevel = A[i].level;
        } 
        else if (A[i].level < B[j].level and B[j].level >= minLevel) {
            C.push_back(B[j]);
            ++j;
            ++countPalestine;
            if (minLevel > B[j].level) minLevel = B[j].level;
        } 
        else {
            // Segundo criterio: Balancear la nacionalidad
            if (countIsrael < countPalestine) {
                C.push_back(A[i]);
                ++i;
                ++countIsrael;
            } 
            else if (countIsrael > countPalestine) {
                C.push_back(B[j]);
                ++j;
                ++countPalestine;
            }
            else {
                // Tercer criterio: Orden Lexicografico
                if (A[i].name < B[j].name) {
                    C.push_back(A[i]);
                    ++i;
                    ++countIsrael;
                }
                else {
                    C.push_back(B[j]);
                    ++j;
                    ++countPalestine;
                }
            }
        }
        // Reseteas el contador cuando el grupo esta hecho
        if (countIsrael + countPalestine == c) countIsrael = countPalestine = 0;
    }

    // Agregar los elementos restantes si hay alguno
    while (i < A.size()) {
        C.push_back(A[i]);
        ++i;
    }
    while (j < B.size()) {
        C.push_back(B[j]);
        ++j;
    }

    return C;
}

// Funcion que ordena en orden lexicografico un grupo de programadores
bool order(Programmer a, Programmer b) {
    return a.name < b.name;
}

int main () {
    int numberOfMembers, numberIsraelian, numberPalestinian;
    while (cin >> numberOfMembers) {
        cin >> numberIsraelian;
        // Creamos un vector para almacenar los Israelies, ya en orden de modo que el primero que entre sera el mejor
        vector<Programmer> israel = read_in_vector(numberIsraelian);

        cin >> numberPalestinian;
        // Creamos un vector para almacenar los Palestinos, ya en orden de modo que el primero que entre sera el mejor
        vector<Programmer> palestine = read_in_vector(numberPalestinian);

        // Unimos los dos vectores
        vector<Programmer> IsraelPalestine = fusion(israel, palestine, numberOfMembers);

        // Los ordenamos lexicograficamente
        int i = 0;
        while (i < IsraelPalestine.size()) {
            sort(IsraelPalestine.begin() + i, IsraelPalestine.begin() + i + numberOfMembers, order);
            i += numberOfMembers;
        }

        // Hacemos el print de los grupos de la manera correcta
        i = 0;
        while (i < IsraelPalestine.size()) {
            cout << IsraelPalestine[i].name;
            for (int j = 1; j < numberOfMembers; ++j) {
                cout << ' ' << IsraelPalestine[i + j].name;
            }
            cout << endl;
            i += numberOfMembers;
        }
        cout << endl;
    }
}
