#include <algorithm>
#include <cstdio>

const int MAX_N = 318'138;
int p[3'001];
bool sieve[MAX_N];

int main() {
  int T, n;

  std::fill(sieve + 2, sieve + MAX_N, true);
  for (int i = 2; i < MAX_N; i++) {
    if (!sieve[i]) continue;
    for (int j = 2; i * j < MAX_N; j++) sieve[i * j] = false;
  }

  for (int k = 0, n = 0, i = 2; i < MAX_N; i++) {
    if (!sieve[i]) continue;
    if (sieve[++k]) p[++n] = i;
  }

  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    printf("%d\n", p[n]);
  }
}