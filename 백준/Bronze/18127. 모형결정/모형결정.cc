#include <cstdio>

int main() {
  long long A, B;
  scanf("%lld%lld", &A, &B);
  printf("%lld", (B + 1) * ((A - 2) * B + 2) / 2);
}