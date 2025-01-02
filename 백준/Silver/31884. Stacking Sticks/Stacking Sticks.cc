#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

map<int, int> m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int Q;
  cin >> Q;

  while (Q--) {
    int q, i;
    cin >> q >> i;
    if (q == 1) {
      int h = max({m[i], m[i + 1], m[i + 2], m[i + 3]}) + 1;
      for (int x = 0; x < 4; x++) m[i + x] = h;
    } else if (q == 2)
      m[i] += 4;
    else
      cout << m[i] << '\n';
  }
}