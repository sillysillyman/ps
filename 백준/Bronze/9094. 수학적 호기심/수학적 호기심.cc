#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T, n, m, c;
  cin >> T;
  while (T--) {
    c = 0;
    cin >> n >> m;
    for (int i = 1; i < n - 1; i++)
      for (int j = i + 1; j < n; j++)
        c += !((i * i + j * j + m) % (i * j));
    cout << c << '\n';
  }
}