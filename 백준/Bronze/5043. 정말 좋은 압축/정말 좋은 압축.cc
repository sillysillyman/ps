#include <cstdio>

int main() {
  long long N, b;

  scanf("%lld %lld", &N, &b);
  printf("%s", (2 > N >> b ? "yes" : "no"));
}