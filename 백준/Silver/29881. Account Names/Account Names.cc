#include <iostream>
#include <map>

using namespace std;

map<string, pair<string, string>> m;

int main() {
  int N;
  cin >> N;

  string s, t;
  for (int i = 0; i < N; i++) {
    cin >> s >> t;
    m[s].first = t;
  }
  for (int i = 0; i < N; i++) {
    cin >> s >> t;
    m[s].second = t;
  }
  for (auto [k, v] : m) cout << v.first << ' ' << v.second << '\n';
}