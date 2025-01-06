#include <cstdio>

int main() {
  int N;
  scanf("%d", &N);

  long long w = 6;
  for (int i = 11; i <= N; i++) w *= i;
  printf("%lld", w);
}