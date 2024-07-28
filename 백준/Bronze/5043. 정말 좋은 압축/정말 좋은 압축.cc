#include <cstdio>

int main() {
  long long N, b;

  scanf("%lld %lld", &N, &b);
  printf("%s", (1 > N >> (b + 1) ? "yes" : "no"));
}