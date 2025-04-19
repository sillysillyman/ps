#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    int N;
    map<string, int> m;

    cin >> N;
    while (N--) {
      int id;
      string s;
      cin >> s >> id;
      if (m.find(s) == m.end() || m.find(s) != m.end() && m[s] > id) m[s] = id;
    }

    vector<int> ids;
    for (auto [k, v] : m) ids.push_back(v);
    sort(ids.begin(), ids.end());

    for (int e : ids) cout << e << ' ';
    cout << '\n';
  }
}