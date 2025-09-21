#include <cstdio>

int main() {
  int n, h;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &h);
    if (h < 48) return printf("False"), 0;
  }
  printf("True");
}