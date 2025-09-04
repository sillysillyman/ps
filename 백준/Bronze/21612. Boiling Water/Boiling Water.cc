#include <cstdio>

int main() {
  int B;
  scanf("%d", &B);
  B = 5 * B - 400;
  printf("%d\n%d", B, B > 100 ? -1 : B < 100 ? 1 : 0);
}