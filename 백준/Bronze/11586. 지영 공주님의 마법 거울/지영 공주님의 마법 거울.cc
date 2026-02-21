#include <cstdio>

int main() {
  int N, K;
  char s[100][100];
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      scanf(" %c", &s[i][j]);
  scanf("%d", &K);
  for (int i = K == 3 ? N - 1 : 0; K == 3 ? i >= 0 : i < N; K == 3 ? i-- : i++) {
    for (int j = K == 2 ? N - 1 : 0; K == 2 ? j >= 0 : j < N; K == 2 ? j-- : j++)
      printf("%c", s[i][j]);
    printf("\n");
  }
}