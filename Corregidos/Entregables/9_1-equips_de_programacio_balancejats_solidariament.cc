// Entregable: PRO1 2023-2024 Q1 D8_T1_online

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Programmer {
    string name;
    int score;
};

typedef vector<Programmer> VP;
typedef vector<string> VS;

void add_member(VS& team, int j, const string& member, int& i, int& n_country) {
    team[j] = member;
    ++i;
    ++n_country;
}

// Pre:
// Returns the list of members of a team
VS create_team(int k, const VP& team_russia, int& i1, int n1, const VP& team_usa, int& i2, int n2) {
    VS team(k);
    int n_russia, n_usa;
    n_russia = n_usa = 0;
    for (int j = 0; j < k; ++j) {
        // if one list is fully explored, no comparison needed:
        if (i2 == n2)  add_member(team, j, team_russia[i1].name, i1, n_russia);
        else if (i1 == n1)  add_member(team, j, team_usa[i2].name, i2, n_usa);
        // priority 1: higher score:
        else if (team_russia[i1].score > team_usa[i2].score)  add_member(team, j, team_russia[i1].name, i1, n_russia);
        else if (team_russia[i1].score < team_usa[i2].score)  add_member(team, j, team_usa[i2].name, i2, n_usa);
        // priority 2: equal country members:
        else if (n_russia < n_usa)  add_member(team, j, team_russia[i1].name, i1, n_russia);
        else if (n_russia > n_usa)  add_member(team, j, team_usa[i2].name, i2, n_usa);
        // priority 3: alphabetical order of names:
        else if (team_russia[i1].name < team_usa[i2].name)  add_member(team, j, team_russia[i1].name, i1, n_russia);
        else  add_member(team, j, team_usa[i2].name, i2, n_usa);
    }
    sort(team.begin(), team.end());

    return team;
}

int main() {
    int k;
    while (cin >> k) {
        int n1, n2;
        cin >> n1;
        VP team_russia(n1);
        for (int i = 0; i < n1; ++i)  cin >> team_russia[i].name >> team_russia[i].score;

        cin >> n2;
        VP team_usa(n2);
        for (int i = 0; i < n2; ++i)  cin >> team_usa[i].name >> team_usa[i].score;

        int n_teams = (n1 + n2)/k;
        int i1, i2;
        i1 = i2 = 0;
        for (int t = 0; t < n_teams; ++t) {
            VS team = create_team(k, team_russia, i1, n1, team_usa, i2, n2);

            cout << team[0];
            for (int i = 1; i < k; ++i)  cout << ' ' << team[i];
            cout << endl;
        }
        cout << endl;
    }
}
