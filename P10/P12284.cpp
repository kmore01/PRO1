/* Program that prints the most frequents words */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> read_in_vector(int size) {
    vector<string> VWords(size);
    for (int i = 0; i < size; ++i) {
        cin >> VWords[i];
    }
    return VWords;
}

bool order (string a, string b) {
    return a < b;
}

int main () {
    int num_words, num_answers;
    while (cin >> num_words >> num_answers) {
        vector<string> sequence = read_in_vector(num_words);
        sort(sequence.begin(), sequence.end(), order);

        // Creeamos un vector para ver cuantas veces se repite cada palabra
        vector<int> num_each_word;
        string prev_word = sequence[0];
        int count = 1;
        for (int i = 1; i < sequence.size(); ++i) {
            if (prev_word != sequence[i]) {
                num_each_word.push_back(count);
                count = 1;
            }
            else ++count;
            prev_word = sequence[i];
        }

        for (int i = 0; i < num_each_word.size(); ++i) {
            cout << num_each_word[i] << ' ';
        }

    }
}