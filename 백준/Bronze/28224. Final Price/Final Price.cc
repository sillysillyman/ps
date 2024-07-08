#include <cstdio>

int main() {
  int n, total = 0;

  scanf("%d", &n);
  while (n--) {
    int price;

    scanf("%d", &price);
    total += price;
  }
  printf("%d", total);
}