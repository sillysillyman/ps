#include <algorithm>
#include <iostream>

using namespace std;

bool found = false;

void dfs(string s, string t) {
  if (s == t) {
    found = true;
    return;
  }
  if (s.length() >= t.length()) return;
  if (t.back() == 'A') dfs(s, t.substr(0, t.length() - 1));
  if (t.front() == 'B') {
    reverse(t.begin(), t.end());
    dfs(s, t.substr(0, t.length() - 1));
  }
}

int main() {
  string S, T;

  cin >> S >> T;
  dfs(S, T);
  cout << found;
}