#include <cstdio>

int main() {
  int res, i;

  scanf("%d", &res);
  for (i = 1; res != 1; i++) {
    if (res & 1)
      res = 3 * res + 1;
    else
      res /= 2;
  }
  printf("%d", i);
}