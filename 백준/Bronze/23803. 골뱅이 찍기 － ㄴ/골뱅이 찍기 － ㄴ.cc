#include <cstdio>

int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < 4 * N; i++) {
    for (int j = 0; j < N; j++) putchar('@');
    putchar('\n');
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 5 * N; j++) putchar('@');
    putchar('\n');
  }
}