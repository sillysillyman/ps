#include <cstdio>

int main() {
  int T, N;
  long long x, r;
  scanf("%d", &T);
  while (T--) {
    r = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      scanf("%lld", &x);
      r += x;
      r %= N;
    }
    printf(r ? "NO\n" : "YES\n");
  }
}