#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_group_word(string word) {
    vector<char> letters;
    for (char letter: word) {
        if (letters.empty()) letters.push_back(letter);
        else {
            if (letter == letters[letters.size() - 1]) continue;
            else {
                if (find(letters.begin(), letters.end(), letter) != letters.end()) return false;
                else letters.push_back(letter);
            }
        }
    }
    return true;
}

int main() {
    int N;
    int cnt = 0;
    string word;

    cin >> N;
    while (N--) {
        cin >> word;
        if (is_group_word(word)) cnt++;
    }
    cout << cnt;
}