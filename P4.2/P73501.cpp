// programa que calcula les parelles consecutives de nombres en ordre creixent

#include <iostream>
using namespace std;

int main () {
    int numseq; // natural
    cin >> numseq;
    for (int i = 0; i < numseq; ++i) {
        int num, contador_parelles = 0; // naturals > 0
        cin >> num;
        int min = num;
        while (num != 0) {
            if (min < num) ++contador_parelles;
            min = num;
            cin >> num;
        }
        cout << contador_parelles << endl;
    }
}