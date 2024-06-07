#include <cstdio>

int main() {
  int T;

  scanf("%d", &T);
  while (T--) {
    int N;

    scanf("%d", &N);
    printf("%d\n", (N + 1) * (N + 1) / 4);
  }
}