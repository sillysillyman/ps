#include <cstdio>

int main() {
  int cnt = 0;
  char line[101];

  while (~scanf("%[^\n]\n", line)) ++cnt;
  printf("%d", cnt);
}