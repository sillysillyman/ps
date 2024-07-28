#include <cstdio>

int main() {
  long long N, b;

  scanf("%lld %lld", &N, &b);
  printf("%s", (1LL << b > N >> 1 ? "yes" : "no"));
}