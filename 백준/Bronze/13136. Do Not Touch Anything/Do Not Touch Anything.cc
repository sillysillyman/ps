#include <cstdio>

int main() {
  long long R, C, N;
  scanf("%lld%lld%lld", &R, &C, &N);
  printf("%lld", ((R + N - 1) / N) * ((C + N - 1) / N));
}