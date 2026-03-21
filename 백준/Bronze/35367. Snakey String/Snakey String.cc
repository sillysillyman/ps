#include <cstdio>

int main() {
  int r, c;
  char C[100][100];
  scanf("%d%d", &r, &c);
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      scanf(" %c", &C[i][j]);
  for (int i = 0; i < c; i++)
    for (int j = 0; j < r; j++)
      if (C[j][i] != '.') printf("%c", C[j][i]);
}