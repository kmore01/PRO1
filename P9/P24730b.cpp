#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Profe {
    string nom;
    int caramels;
    int pastanagues;
};

bool ordre(const Profe &a, const Profe &b) {
    /* dona true ssi el Profe a va abans que el b */
    if (a.caramels != b.caramels) return a.caramels > b.caramels;
    else if (a.pastanagues != b.pastanagues) {
        return a.pastanagues > b.pastanagues;
    }
    else if (a.nom.size() != b.nom.size()) {
        return a.nom.size() < b.nom.size();
    }
    else return a.nom < b.nom;
}

int main () {
    /* int numblocs;
    cin >> numblocs;
    for(int i = 0; i < numblocs; ++i) {
        cin >> profes[i].nom;
        cin >> profes[i].caramels;
        cin >> profes[i].pastanagues;
    }
    */

    int numprofes;
    cin >> numprofes;
    vector<Profe> profes(numprofes);

    for (int i = 0; i < numprofes; ++i) {
        cin >> profes[i].nom >> profes[i].caramels >> profes[i].pastanagues;
    }

    sort(profes.begin(), profes.end(), ordre);

    for (int i = 0; i < numprofes; ++i) {
        cout << profes[i].nom << endl;
    }
    cout << endl;
}