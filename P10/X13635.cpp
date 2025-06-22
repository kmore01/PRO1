/* Program that */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Track {
  string artist, title, genre;
  int year;
};

bool order() {

}
// ....

vector<Track> read_tracks(int n) {
    vector<Track> VSongs(n);
    for (int i = 0; i < n; ++i) {
        cin >> VSongs[i].artist >> VSongs[i].title >> VSongs[i].genre;
        cin >> VSongs[i].year;
    }
    return VSongs;
}

void print_track(const Track &t) {
  cout << t.artist;
  cout << " (" << t.year;
  cout << ") " << t.title << " (" << t.genre << ")" << endl;
}

int main() {
    int size; // size ≥ 0
    cin >> size;
    vector<Track> songs = read_tracks(size);
    sort(songs.begin(), songs.end(), order);

  //....
}