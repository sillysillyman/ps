#include <cstdio>

int main() {
  int N, M;
  long long S;
  scanf("%d%d%lld", &N, &M, &S);
  printf("%lld", M * S < (M + 1) * S * (100 - N) / 100 ? M * S : (M + 1) * S * (100 - N) / 100);
}