#include <cstdio>

int N, cnt;
char yesterday[101], today[101];

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf(" %c", &yesterday[i]);
  for (int i = 0; i < N; i++) scanf(" %c", &today[i]);
  for (int i = 0; i < N; i++) cnt += (yesterday[i] == 'C') & (today[i] == 'C');
  printf("%d", cnt);
}