#include <cstdio>

int main() {
  int H, M;
  scanf("%d%d", &H, &M);
  printf("%d", 60 * (H - 9) + M);
}