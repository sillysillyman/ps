#include <cstdio>

int main() {
  long long N, R;

  scanf("%lld%lld", &N, &R);
  printf("%lld\n", (N + 1) + 2 * (R - 1));
}