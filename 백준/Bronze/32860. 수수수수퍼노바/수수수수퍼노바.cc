#include <cstdio>

int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  printf("SN %d", N);
  if (M < 27)
    printf("%c", 'A' + M - 1);
  else {
    M -= 27;
    printf("%c%c\n", 'a' + M / 26, 'a' + M % 26);
  } 
}