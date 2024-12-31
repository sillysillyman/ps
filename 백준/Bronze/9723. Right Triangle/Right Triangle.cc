#include <algorithm>
#include <iostream>

using namespace std;

int sides[3];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    for (int i = 0; i < 3; i++) cin >> sides[i];
    sort(sides, sides + 3);
    cout << "Case #" << t << ": "
         << (sides[2] * sides[2] == sides[0] * sides[0] + sides[1] * sides[1]
                 ? "YES"
                 : "NO")
         << '\n';
  }
}