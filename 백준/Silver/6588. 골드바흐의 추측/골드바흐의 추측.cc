#include <iostream>

using namespace std;

int sieve[1000001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 3; i < 1000001; i += 2) sieve[i] = 1;
  for (int i = 3; i < 1000001; i += 2) {
    if (sieve[i]) {
      for (int j = 3; i * j < 1000001; j += 2) sieve[i * j] = 0;
    }
  }

  int n;

  while (true) {
    cin >> n;
    if (n == 0) break;
    for (int i = 3; i < n; i += 2) {
      if (sieve[i] && sieve[n - i]) {
        cout << n << " = " << i << " + " << n - i << '\n';
        break;
      }
    }
  }
}