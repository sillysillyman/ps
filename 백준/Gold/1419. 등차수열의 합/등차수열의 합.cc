#include <cstdio>

int main() {
  int l, r, k;
  scanf("%d%d%d", &l, &r, &k);

  if (k == 2)
    printf("%d", r < 3 ? 0 : r - (l >= 3 ? l - 1 : 2));
  else if (k == 3)
    printf("%d", r < 6 ? 0 : r / 3 - (l >= 6 ? (l - 1) / 3 : 1));
  else if (k == 4)
    printf("%d",
           r < 10 ? 0
                  : r / 2 - (l >= 10 ? (l - 1) / 2 : 4) - (l <= 12 && 12 <= r));
  else
    printf("%d", r < 15 ? 0 : r / 5 - (l >= 15 ? (l - 1) / 5 : 2));
}