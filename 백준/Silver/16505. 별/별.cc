#include <cstdio>

char stars[1'024][1'024];

void rec(int x, int y, int size) {
  if (!size) return;

  --size;
  for (int k = 1, i = x + (1 << size) - 1; i > x; i--, k++)
    for (int j = y + k; j < y + (1 << size); j++) stars[i][j] = ' ';

  rec(x, y, size);
  rec(x, y + (1 << size), size);
  rec(x + (1 << size), y, size);
}

int main() {
  int N;

  scanf("%d", &N);
  for (int i = 0; i < 1 << N; i++)
    for (int j = 0; j < (1 << N) - i; j++) stars[i][j] = '*';

  rec(0, 0, N);

  for (int i = 0; i < 1 << N; i++) {
    for (int j = 0; j < (1 << N) - i; j++) printf("%c", stars[i][j]);
    puts("");
  }
}