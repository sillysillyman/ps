#include <cstdio>

int main() {
  int D, E, Q;
  scanf("%d%d", &D, &E);
  while (E--) {
    char c;
    scanf(" %c%d", &c, &Q);
    D += (c == '-' ? -1 : 1) * Q;
  }
  printf("%d", D);
}