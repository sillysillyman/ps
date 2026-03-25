#include <cstdio>

int main() {
  int T, n, m, c;
  scanf("%d", &T);
  while (T--) {
    c = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n - 1; i++)
      for (int j = i + 1; j < n; j++)
        c += !((i * i + j * j + m) % (i * j));
    printf("%d\n", c);
  }
}