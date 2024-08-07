#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int t = 1;; t++) {
    int n;
    cin >> n;
    if (!n) break;

    string str;
    map<char, int> order;
    vector<string> words(n);

    cin >> str;
    for (int i = 0; i < 26; i++) order[str[i]] = i;
    for (int i = 0; i < n; i++) cin >> words[i];
    sort(words.begin(), words.end(), [&order](string& a, string& b) {
      int len = min(a.length(), b.length());
      for (int i = 0; i < len; i++) {
        if (order[a[i]] == order[b[i]]) continue;
        return (order[a[i]] < order[b[i]]);
      }
      return a.length() < b.length();
    });
    cout << "year " << t << '\n';
    for (auto& word : words) cout << word << '\n';
  }
}