#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;

  cin >> t;
  while (t--) {
    int N;

    cin >> N;
    cout << N * (1 + N) / 2 << ' ' << N * N << ' ' << N * (N + 1) << '\n';
  }
}