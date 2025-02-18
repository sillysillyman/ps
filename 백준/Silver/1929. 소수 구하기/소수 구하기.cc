#include <cstdio>

const int MAX_N = 1e6;
bool sieve[MAX_N + 1];

int main() {
  int M, N;
  scanf("%d%d", &M, &N);

  for (int i = 2; i <= N; i++) sieve[i] = 1;
  for (int i = 2; i <= N; i++) {
    if (!sieve[i]) continue;
    for (int j = 2; i * j <= N; j++) sieve[i * j] = 0;
  }
  for (int i = M; i <= N; i++)
    if (sieve[i]) printf("%d\n", i);
}