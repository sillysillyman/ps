#include <cstdio>

int n, c, x, y, z;

int main() {
  scanf("%d%d", &n, &c);
  while (n--) {
    int a;
    char t[9];

    scanf("%d%s", &a, t);
    z += a;
    if (t[1] == 'e')
      x += a;
    else if (t[2] == 'l')
      y += a;
  }
  printf("%d\n%d\n%.6f", z, x, c * (double)(z - 0.5 * y));
}