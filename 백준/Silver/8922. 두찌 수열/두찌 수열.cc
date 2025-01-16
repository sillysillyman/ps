#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool all_zero(vector<int>& v) {
  for (int x : v)
    if (x != 0) return false;
  return true;
}

bool is_looped(vector<int> v) {
  map<vector<int>, bool> visited;
  visited[v] = true;

  int n = v.size();
  vector<int> curr(v);
  vector<int> next(n);

  while (!all_zero(curr)) {
    for (int i = 0; i < n; i++) {
      if (i == n - 1)
        next[i] = abs(curr[n - 1] - curr[0]);
      else
        next[i] = abs(curr[i] - curr[i + 1]);
    }

    if (visited.find(next) != visited.end()) return true;

    visited[next] = true;
    curr = next;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    vector<int> seq(n);
    for (int& x : seq) cin >> x;
    cout << (is_looped(seq) ? "LOOP\n" : "ZERO\n");
  }
}