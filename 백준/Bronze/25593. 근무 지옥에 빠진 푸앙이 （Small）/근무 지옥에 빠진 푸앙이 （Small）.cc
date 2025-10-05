#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int N;
string s;
map<string, int> m;

int main() {
  cin >> N;
  while (N--) {
    for (int i = 0; i < 28; i++) {
      cin >> s;
      if (s == "-") continue;
      m[s] += i > 6 && i < 14 ? 6 : i > 20 ? 10 : 4;
    }
  }
  auto [min_it, max_it] = minmax_element(m.begin(), m.end(), [](auto &a, auto &b) { return a.second < b.second; });
  cout << (max_it->second - min_it->second < 13 ? "Yes" : "No");
}