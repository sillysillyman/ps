#include <cstdio>

int main() {
  int N, T = 0;
  scanf("%d", &N);
  while (N--) {
    char p;
    scanf(" %c%*s", &p);
    T += p == 'P'   ? 15e2
         : p == 'M' ? 6e3
         : p == 'S' ? 155e2
         : p == 'C' ? 4e4
         : p == 'T' ? 75e3
                    : 125e3;
  }
  printf("%d", T);
}