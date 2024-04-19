#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;

  cin >> T;
  while (T--) {
    int s, n;

    cin >> s >> n;
    for (int q, p, i = 0; i < n; i++) {
      cin >> q >> p;
      s += q * p;
    }
    cout << s << '\n';
  }
}