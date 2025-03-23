#include <iostream>
#include <map>

using namespace std;

map<string, int> m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    int k;
    string name;
    cin >> name >> k;
    m[name] += k;
  }

  for (auto &[k, v] : m) cout << k << ' ' << v << '\n';
}