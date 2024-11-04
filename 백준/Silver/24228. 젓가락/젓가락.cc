#include <cstdio>

int main() {
  long long N, R;

  scanf("%lld%lld", &N, &R);
  printf("%lld", ++N + 2 * --R);
}