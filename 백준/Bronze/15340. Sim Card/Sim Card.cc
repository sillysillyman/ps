#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (true) {
    int c, d;

    cin >> c >> d;
    if (c == 0 && d == 0) break;
    cout << min({30 * c + 40 * d, 35 * c + 30 * d, 40 * c + 20 * d}) << '\n';
  }
}