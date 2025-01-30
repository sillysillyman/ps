#include <cstdio>

int main() {
  int N;
  scanf("%d", &N);
  if (!N) return printf("NO"), 0;

  long long n = 1;
  while (3 * n <= N) n *= 3;
  while (n && N) {
    if (N >= n) N -= n;
    n /= 3;
  }
  printf("%s", N ? "NO" : "YES");
}