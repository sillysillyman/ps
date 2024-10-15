#include <cstdio>

char ans[3];

int main() {
  int N, F;

  scanf("%d%d", &N, &F);
  N = N / 100 * 100;
  for (int i = N; i < N + 100; i++) {
    if (!(i % F)) {
      ans[0] = i % 100 / 10 + '0';
      ans[1] = i % 10 + '0';
      break;
    }
  }
  printf("%s", ans);
}