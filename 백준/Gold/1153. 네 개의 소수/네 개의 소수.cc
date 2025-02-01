#include <cstdio>

bool is_prime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i * i <= n; i++)
    if (!(n % i)) return false;
  return true;
}

int main() {
  int N;
  scanf("%d", &N);

  if (N & 1) {
    for (int i = 2; i < N / 2; i++)
      if (is_prime(i) && is_prime(N - i - 5))
        return printf("2 3 %d %d", i, N - i - 5), 0;
  } else {
    for (int i = 2; i < N / 2; i++)
      if (is_prime(i) && is_prime(N - i - 4))
        return printf("2 2 %d %d", i, N - i - 4), 0;
  }
  printf("-1");
}