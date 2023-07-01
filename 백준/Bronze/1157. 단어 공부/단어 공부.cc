#include <iostream>
#include <vector>

using namespace std;

int main() {
    string word;
    int max_cnt = 0;
    int cnts[26] = {};
    vector<char> most_frequent_letter;

    cin >> word;
    for (int i = 0; i < word.length(); i++) {
        word[i] = toupper(word[i]);
    }
    for (char letter : word) {
        cnts[letter - 'A']++;
    }
    for (int cnt : cnts) {
        if (cnt > max_cnt) max_cnt = cnt;
    }
    for (int i = 0; i < 26; i++) {
        if (cnts[i] == max_cnt) most_frequent_letter.push_back(i + 'A');
    }
    if (most_frequent_letter.size() > 1) cout << '?';
    else cout << most_frequent_letter[0];
}