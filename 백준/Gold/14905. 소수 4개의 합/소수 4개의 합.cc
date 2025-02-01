#include <cstdio>

bool is_prime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i * i <= n; i++)
    if (!(n % i)) return false;
  return true;
}

void solve(int n) {
  if (n & 1) {
    for (int i = 2; i < n / 2; i++)
      if (is_prime(i) && is_prime(n - i - 5)) {
        printf("2 3 %d %d\n", i, n - i - 5);
        return;
      }
  } else {
    for (int i = 2; i < n / 2; i++)
      if (is_prime(i) && is_prime(n - i - 4)) {
        printf("2 2 %d %d\n", i, n - i - 4);
        return;
      }
  }
  printf("Impossible.\n");
}

int main() {
  int N;
  while (~scanf("%d", &N)) solve(N);
}