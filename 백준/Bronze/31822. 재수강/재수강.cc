#include <cstdio>

int a, b, c;

int main() {
  scanf("%5d%*s %*d", &a);
  while (~scanf(" %5d%*s", &b)) c += a == b;
  printf("%d", c);
}