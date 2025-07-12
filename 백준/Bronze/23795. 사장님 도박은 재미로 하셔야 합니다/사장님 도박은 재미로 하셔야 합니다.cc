#include <cstdio>

int s, x;

int main() {
  while (scanf("%d", &x) && x != -1) s += x;
  printf("%d", s);
}