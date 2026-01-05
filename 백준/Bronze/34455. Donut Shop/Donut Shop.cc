#include <cstdio>

int main() {
  int D, E, Q;
  scanf("%d%d", &D, &E);
  while (E--) {
    char c;
    scanf(" %c%d", &c, &Q);
    D += c == '-' ? -Q : Q;
  }
  printf("%d", D);
}