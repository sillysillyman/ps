#include <cstdio>

char mat[3][5] = {"G...", ".I.T", "..S."};

int main() {
  int K;
  scanf("%d", &K);
  for (int i = 0; i < 3; i++)
    for (int r = 0; r < K; r++) {
      for (int j = 0; j < 4; j++)
        for (int c = 0; c < K; c++)
          printf("%c", mat[i][j]);
      printf("\n");
    }
}