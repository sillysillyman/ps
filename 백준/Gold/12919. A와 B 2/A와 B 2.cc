#include <algorithm>
#include <iostream>

using namespace std;

bool found = false;

void dfs(string s, string t) {
//   cout << t << endl;
  if (s == t) {
    found = true;
    return;
  }
  if (s.length() >= t.length()) return;

  if (t.back() == 'A') {
    dfs(s, t.substr(0, t.length() - 1));

  }
  if (t.front() == 'B') {
    // string reversed = t;

    // reverse(reversed.begin(), reversed.end());
    reverse(t.begin(), t.end());
    // cout << "reversed: " << reversed << endl;
    // dfs(s, reversed.substr(0, reversed.length() - 1));
    dfs(s, t.substr(0, t.length() - 1));
  }
//   dfs(s, t.substr(0, t.length() - 1));
}

int main() {
  string S, T;

  cin >> S >> T;
  dfs(S, T);
  cout << found;
}