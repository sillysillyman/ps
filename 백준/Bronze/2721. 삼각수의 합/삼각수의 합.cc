#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;

  cin >> T;
  while (T--) {
    int n;
    int sum = 0;

    cin >> n;
    for (int i = 1; i <= n; i++) sum += i * (i + 1) * (i + 2) / 2;
    cout << sum << '\n';
  }
}