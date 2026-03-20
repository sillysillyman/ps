#include <cstdio>

int main() {
  int N, n, s;
  scanf("%d", &N);
  while (N--) {
    scanf("%d", &n);
    s = -n;
    for (int i = 1; i * i <= n; i++) s += n % i ? 0 : i * i == n ? i : i + n / i;
    printf("%d is %s number.\n\n", n, s < n ? "a deficient" : s > n ? "an abundant" : "a perfect");
  }
}