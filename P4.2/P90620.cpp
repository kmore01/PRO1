// programa que calcula si hi ha algun pic d'estat en una sequencia finaliza 0

#include <iostream>
using namespace std;
const int PI_STAT = 3143;

int main () {
    int num; // enter > 0
    cin >> num;
    int num_anterior = num;
    cin >> num;
    int num_medio = num;
    cin >> num;
    int num_posterior = num;
    bool pic = false;
    while (not pic and num_posterior != 0) {
        if (num_medio > PI_STAT) {
            if (num_medio > num_posterior and num_medio > num_anterior) pic = true;
        }
        num_anterior = num_medio;
        num_medio = num_posterior;
        cin >> num_posterior;
    }
    if (pic) cout << "SI" << endl;
    else cout << "NO" << endl;
}