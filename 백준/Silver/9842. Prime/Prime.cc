#include <cstdio>

const int SIZE = 104'730;
int sieve[SIZE];

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 2; i < SIZE; i++) sieve[i] = 1;
  for (int i = 2; i < SIZE; i++) {
    if (!sieve[i]) continue;
    for (int j = 2; i * j < SIZE; j++) sieve[i * j] = 0;
  }

  int cnt = 0;
  for (int i = 0; i < SIZE; i++) {
    if (sieve[i]) cnt++;
    if (cnt == n) {
      printf("%d", i);
      break;
    }
  }
}