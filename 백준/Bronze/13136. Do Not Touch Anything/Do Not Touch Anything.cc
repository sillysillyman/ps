#include <cstdio>

int main() {
  long long R, C, N;
  scanf("%lld%lld%lld", &R, &C, &N);
  R = ((R + N - 1) / N) * N;
  C = ((C + N - 1) / N) * N;
  printf("%lld", R * C / (N * N));
}