#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;
  long long n = -1e18 - 1, m;
  cin >> N;
  while (N--) {
    cin >> m;
    if (m == n) return cout << 0, 0;
    n = m;
  }
  cout << 1;
}