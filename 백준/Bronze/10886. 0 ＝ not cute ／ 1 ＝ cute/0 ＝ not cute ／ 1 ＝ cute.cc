#include <cstdio>

int N, n, c;

int main() {
  scanf("%d", &N);
  while (N--) {
    scanf("%d", &n);
    c += 2 * n - 1;
  }
  printf("Junhee is %scute!", c > 0 ? "" : "not ");
}