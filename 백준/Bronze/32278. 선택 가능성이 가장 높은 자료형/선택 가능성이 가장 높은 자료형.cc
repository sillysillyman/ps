#include <climits>
#include <cstdio>

int main() {
  long long N;
  scanf("%lld", &N);
  if (N < 0) N  = ~N;
  printf(N <= SHRT_MAX ? "short" : N <= INT_MAX ? "int" : "long long");
}