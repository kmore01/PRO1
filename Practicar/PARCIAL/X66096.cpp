// programa que calcula les emissions de Co2 d'una accio concreta

#include <iostream>
using namespace std;

int main () {
    cout.setf(ios::fixed);
    cout.precision(2); 
    int any; // enters positius
    double emissions_totals;
    string accio;
    cin >> any >> emissions_totals >> accio;
    if (accio == "making_things") {
        cout << "Making things produced " << double(0.31) * double(emissions_totals) << " CO2 Gt in " << any << endl;
    }
    else if (accio == "pluggin_in") {
        cout << "Pluggin in produced " << double(0.27) * double(emissions_totals) << " CO2 Gt in " << any << endl;
    }
    else if (accio == "growing_things") {
        cout << "Growing things produced " << double(0.19) * double(emissions_totals) << " CO2 Gt in " << any << endl;
    }
    else if (accio == "getting_around") {
        cout << "Getting around produced " << double(0.16) * double(emissions_totals) << " CO2 Gt in " << any << endl;
    }
    else {
        cout << "Keeping warm and cold produced " << double(0.07) * double(emissions_totals) << " CO2 Gt in " << any << endl;
    }


}