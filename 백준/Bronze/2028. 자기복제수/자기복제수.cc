#include <cmath>
#include <cstdio>

int main() {
  int T, N;

  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    if (N == (N * N) % (int)pow(10, (int)log10(N) + 1))
      puts("YES");
    else
      puts("NO");
  }
}