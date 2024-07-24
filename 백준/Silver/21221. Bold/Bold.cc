#include <cstdio>

char board[100][100];
char bolded[100][100];

int main() {
  int n, m;

  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", board[i]);
    for (int j = 0; j < m; j++) bolded[i][j] = board[i][j];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == '.') continue;
      bolded[i][j + 1] = '#';
      bolded[i + 1][j] = '#';
      bolded[i + 1][j + 1] = '#';
    }
  }
  for (int i = 0; i < n; i++) printf("%s\n", bolded[i]);
}