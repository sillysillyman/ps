#include <cstdio>

int main() {
  char x;
  int L, N;
  scanf("%d", &L);
  while (L--) {
    scanf("%d %c", &N, &x);
    while (N--) printf("%c", x);
    printf("\n");
  }
}