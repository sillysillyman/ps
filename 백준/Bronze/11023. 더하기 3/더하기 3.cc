#include <cstdio>

int main() {
  int n, sum = 0;

  while (~scanf("%d", &n)) sum += n;
  printf("%d\n", sum);
}