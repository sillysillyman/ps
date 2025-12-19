#include <cstdio>

int main() {
  char s[21];
  scanf("%s", s);
  for (int i = 0; i < 9; i++) {
    printf(":%s:", i == 4 ? s : "fan");
    if (!((i + 1) % 3)) printf("\n");
  }
}