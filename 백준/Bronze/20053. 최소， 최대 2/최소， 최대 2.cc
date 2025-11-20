#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T, N, n, M, m;
  cin >> T;
  while (T--) {
    M = -1e6, m = 1e6;
    cin >> N;
    while (N--) {
      cin >> n;
      if (n > M) M = n;
      if (n < m) m = n;
    }
    cout << m << ' ' << M << '\n';
  }
}