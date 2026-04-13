#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T, N;
  long long x, r;
  cin >> T;
  while (T--) {
    cin >> N;
    r = 0;
    for (int i = 0; i < N; i++) {
      cin >> x;
      r += x;
      r %= N;
    }
    cout << (r ? "NO\n" : "YES\n");
  }
}