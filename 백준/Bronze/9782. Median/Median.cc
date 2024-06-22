#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 0;

  cout << fixed;
  cout.precision(1);
  while (true) {
    int n;
    float median;

    cin >> n;
    if (n == 0) break;
    for (int num, i = 0; i < n; i++) {
      cin >> num;
      if (n & 1 && i == n / 2)
        median = num;
      else if (i == n / 2 - 1)
        median = num;
      else if (i == n / 2)
        median = (median + num) / 2;
    }
    cout << "Case " << ++t << ": " << median << '\n';
  }
}