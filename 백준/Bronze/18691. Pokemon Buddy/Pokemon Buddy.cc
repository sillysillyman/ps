#include <cstdio>

int main() {
  int T, G, C, E;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &G, &C, &E);
    printf("%d\n", C > E ? 0 : (G == 1 ? 1 : G == 2 ? 3 : 5) * (E - C));
  }
}