#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (const string &a, const string &b) {
    if (a.length() < b.length()) return true;
    else if (a.length() == b.length()) {
        if (a < b) return true;
        else return false;
    } else return false;
}

int main() {
    int N;
    string word;
    vector<string> words;

    cin >> N;
    while (N--) {
        cin >> word;
        if (find(words.begin(), words.end(), word) == words.end()) words.push_back(word);
    }
    sort(words.begin(), words.end(), cmp);
    for (string word : words) {
        cout << word << '\n';
    }
}