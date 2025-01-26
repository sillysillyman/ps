#include <cstdio>

int main() {
  int T, S;
  scanf("%d%d", &T, &S);
  printf("%d", !S && 11 < T && T < 17 ? 320 : 280);
}