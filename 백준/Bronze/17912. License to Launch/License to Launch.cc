#include <iostream>

using namespace std;

int n, m, M = 1e9;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int x, i = 0; i < n; i++) {
    cin >> x;
    if (x < M) M = x, m = i;
  }
  cout << m;
}