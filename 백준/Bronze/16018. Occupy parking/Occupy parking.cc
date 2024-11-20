#include <cstdio>

int N, cnt;
char y[101], t[101];

int main() {
  scanf("%d %s %s", &N, y, t);
  for (int i = 0; i < N; i++) cnt += (y[i] == 'C') & (t[i] == 'C');
  printf("%d", cnt);
}