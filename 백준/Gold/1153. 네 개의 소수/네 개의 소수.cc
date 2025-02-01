#include <cstdio>

const int MAX_N = 1e6;
bool sieve[MAX_N + 1];
int primes[78'498];

int main() {
  int N;
  scanf("%d", &N);

  for (int i = 2; i < MAX_N + 1; i++) sieve[i] = true;
  for (int i = 2; i < MAX_N + 1; i++)
    if (sieve[i])
      for (int j = 2; i * j < MAX_N + 1; j++) sieve[i * j] = false;

  int idx = 0;
  for (int i = 0; i <= N; i++)
    if (sieve[i]) primes[idx++] = i;

  for (int i = 0; i < idx; i++)
    for (int j = i; j < idx; j++)
      for (int k = j; k < idx; k++)
        if (int r = N - (primes[i] + primes[j] + primes[k]); sieve[r])
          return printf("%d %d %d %d", primes[i], primes[j], primes[k], r), 0;

  printf("-1");
}