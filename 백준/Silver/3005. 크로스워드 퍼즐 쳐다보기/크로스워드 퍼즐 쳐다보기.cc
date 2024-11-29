#include <cstdio>
#include <cstring>

char ans[21] = {'z' + 1};
char board[21][21];

int main() {
  int R, C;

  scanf("%d%d", &R, &C);
  for (int i = 0; i <= R; i++) board[i][0] = '#';
  for (int j = 0; j <= C; j++) board[0][j] = '#';
  for (int i = 1; i <= R; i++)
    for (int j = 1; j <= C; j++) scanf(" %c", &board[i][j]);

  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      int idx = 0;
      char word[21] = {'\0'};

      if (board[i - 1][j] == '#') {
        for (int k = i; k <= R && board[k][j] != '#'; k++)
          word[idx++] = board[k][j];
      } else if (board[i][j - 1] == '#') {
        for (int k = j; k <= C && board[i][k] != '#'; k++)
          word[idx++] = board[i][k];
      }
      if (strlen(word) > 1 && strcmp(word, ans) < 0) strcpy(ans, word);
    }
  }
  printf("%s", ans);
}