#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N, L, R, c, p, l = 0, r = 0, M = 0, m = 1e9;
  cin >> N >> L >> R;
  L--, R--;
  for (int i = 0; i < N; i++) {
    cin >> c;
    if (i) {
      if (i <= L - 1 && p > c) return cout << 0, 0;
      if (i >= R + 2 && p > c) return cout << 0, 0;
    }
    if (i == L - 1) l = c;
    if (i == R + 1) r = c;
    if (L <= i && i <= R) {
      M = max(M, c);
      m = min(m, c);
    }
    p = c;
  }
  cout << (L && l > m || R < N - 1 && M > r ? 0 : 1);
}