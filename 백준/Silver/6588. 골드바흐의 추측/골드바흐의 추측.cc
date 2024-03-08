#include <iostream>

using namespace std;

const int MAX_N = 1'000'000;
int sieve[MAX_N + 1];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 3; i <= MAX_N; i += 2) sieve[i] = 1;
  for (int i = 3; i <= MAX_N; i += 2) {
    if (sieve[i]) {
      for (int j = 3; i * j <= MAX_N; j += 2) sieve[i * j] = 0;
    }
  }

  int n;

  while (cin >> n) {
    if (n == 0) break;
    for (int i = 3; i < n; i += 2) {
      if (sieve[i] && sieve[n - i]) {
        cout << n << " = " << i << " + " << n - i << '\n';
        break;
      }
    }
  }
}