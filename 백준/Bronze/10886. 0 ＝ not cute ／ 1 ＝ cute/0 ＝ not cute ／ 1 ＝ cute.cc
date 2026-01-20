#include <cstdio>

int main() {
  int N, n, c = 0;
  scanf("%d", &N);
  while (N--) {
    scanf("%d", &n);
    c += n ? 1 : -1;
  }
  printf("Junhee is %scute!", c > 0 ? "" : "not ");
}