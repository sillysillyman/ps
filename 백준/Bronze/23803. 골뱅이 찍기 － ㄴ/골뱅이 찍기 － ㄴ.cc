#include <cstdio>

int main() {
  int N, i, j;
  scanf("%d", &N);
  for (i = 0; i < 4 * N; i++) {
    for (j = 0; j < N; j++) printf("@");
    puts("");
  }
  for (i = 0; i < N; i++) {
    for (j = 0; j < 5 * N; j++) printf("@");
    puts("");
  }
}