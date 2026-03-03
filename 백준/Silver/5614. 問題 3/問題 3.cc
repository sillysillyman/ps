#include <iostream>
#include <map>

using namespace std;

struct Cmp {
  bool operator()(const string &a, const string &b) const {
    return a.size() != b.size() ? a.size() < b.size() : a < b;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  map<string, int, Cmp> m;

  cin >> n;
  while (n--) {
    string s;
    cin >> s >> x;
    m[s] += x;
  }
  for (auto &[k, v] : m) cout << k << ' ' << v << '\n';
}