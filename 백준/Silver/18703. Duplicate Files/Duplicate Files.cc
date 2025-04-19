#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> ids;
unordered_map<string, int> um;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    ids.clear();
    um.clear();

    int N;

    cin >> N;
    while (N--) {
      int id;
      string s;
      cin >> s >> id;
      if (um.find(s) == um.end() || um[s] > id) um[s] = id;
    }

    for (auto [k, v] : um) ids.push_back(v);
    sort(ids.begin(), ids.end());

    for (int e : ids) cout << e << ' ';
    cout << '\n';
  }
}