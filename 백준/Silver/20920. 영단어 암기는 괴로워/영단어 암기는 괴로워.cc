#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
    if (a.second == b.second) {
        if (a.first.length() == b.first.length()) {
            return a.first < b.first;
        }
        return a.first.length() > b.first.length();
    }
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    string word;
    map<string, int> vocabularies;

    cin >> N >> M;
    while (N--) {
        cin >> word;
        if (word.length() >= M) vocabularies[word]++;
    }

    vector<pair<string, int>> v(vocabularies.begin(), vocabularies.end());

    sort(v.begin(), v.end(), cmp);
    for (auto word : v) cout << word.first << '\n';
}