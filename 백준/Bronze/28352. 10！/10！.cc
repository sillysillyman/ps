#include <cstdio>

int main() {
  int N;
  scanf("%d", &N);

  long long w = 1;
  for (int i = 11; i <= N; i++) w *= i;
  printf("%lld", 6 * w);
}