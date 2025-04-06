#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int t = 1;; t++) {
    int n;
    cin >> n;
    if (n < 0) break;

    long long X = 0, Y = 0, M = 0;
    for (int x, y, m, i = 0; i < n; i++) {
      cin >> x >> y >> m;
      X += x * m;
      Y += y * m;
      M += m;
    }

    cout << fixed;
    cout.precision(2);
    cout << "Case " << t << ": " << (double)X / M << ' ' << (double)Y / M
         << '\n';
  }
}