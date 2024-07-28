#include <cstdio>

int main() {
  long long N, b;

  scanf("%lld %lld", &N, &b);
  printf("%s", (1LL << (b + 1) > N ? "yes" : "no"));
}