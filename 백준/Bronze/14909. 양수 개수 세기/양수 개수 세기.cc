#include <cstdio>

int n, cnt;

int main() {
  while (~scanf("%d", &n)) cnt += n > 0;
  printf("%d", cnt);
}