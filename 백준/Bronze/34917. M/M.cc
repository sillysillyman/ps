#include <cstdio>

int main() {
  int T, N;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++)
        printf(j == 0 || j == N - 1 || (i <= N / 2 && (i == j || i + j == N - 1)) ? "#" : ".");
      printf("\n");
    }
  }
}