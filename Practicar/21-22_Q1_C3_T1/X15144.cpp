// Programa que ordena articulos de una enciclopedia

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Article {
    string identifier;
    string topic;
    int freq;
};

// Funcion que ordena articulos segun el topico, busquedas y orden lexicografico
bool order(Article a, Article b) {
    if (a.topic != b.topic) return a.topic < b.topic;
    else if (a.freq != b.freq) return a.freq > b.freq;
    else return a.identifier < b.identifier;
}

//pre: n > 0
//post: returns article vector formed by input channel data
vector<Article> initialize_art_vector(int n) {
    vector<Article> VInputs(n);
    for (int i = 0; i < n; ++i) {
        cin >> VInputs[i].identifier >> VInputs[i].topic;
    }
    string busqueda;
    while (cin >> busqueda) {
        for (int i = 0; i < n; ++i) {
            if (busqueda == VInputs[i].identifier) ++VInputs[i].freq;
        }
    }

    return VInputs;
}


//pre: v is non-empty
//post: write vector on output
// Procedimiento que imprime la respuesta final ordenada
void write_art_vector(vector<Article> &respuesta) {
    // Los ordenamos segun los criterios establecidos
    sort(respuesta.begin(), respuesta.end(), order);
    for (int i = 0; i < respuesta.size(); ++i) {
        cout << respuesta[i].topic << ' ' << respuesta[i].freq << ' ' 
             << respuesta[i].identifier << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<Article> v = initialize_art_vector(n);
    write_art_vector(v);
}