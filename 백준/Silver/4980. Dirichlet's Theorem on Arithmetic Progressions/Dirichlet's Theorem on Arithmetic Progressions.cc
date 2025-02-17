#include <cstdio>

bool sieve[1'000'000];

int main() {
  for (int i = 2; i < 1e6; i++) sieve[i] = 1;
  for (int i = 2; i < 1e6; i++) {
    if (!sieve[i]) continue;
    for (int j = 2; i * j < 1e6; j++) sieve[i * j] = 0;
  }

  int a, d, n;
  while (scanf("%d%d%d", &a, &d, &n) && a && d && n) {
    int cnt = 0;
    for (int i = a;; i += d) {
      if (sieve[i]) ++cnt;
      if (cnt == n) {
        printf("%d\n", i);
        break;
      }
    }
  }
}