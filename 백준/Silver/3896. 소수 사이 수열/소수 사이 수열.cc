#include <iostream>

using namespace std;

int sieve[1299710];

int main() {
  int T, k;

  fill(sieve, sieve + 1299710, 1);
  sieve[0] = 0;
  sieve[1] = 0;
  for (int i = 2; i < 1299710; i++) {
    if (sieve[i] == 0) continue;
    for (int j = 2; i * j < 1299710; j++) sieve[i * j] = 0;
  }
  cin >> T;
  while (T--) {
    int len = 0;

    cin >> k;
    if (sieve[k])
      cout << 0 << '\n';
    else {
      len = 1;
      for (int i = k - 1; i >= 0; i--) {
        if (sieve[i]) break;
        len++;
      }
      for (int i = k + 1; i < 1299710; i++) {
        if (sieve[i]) break;
        len++;
      }
      len++;
      cout << len << '\n';
    }
  }
}