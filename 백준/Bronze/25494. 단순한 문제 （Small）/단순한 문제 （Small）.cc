#include <cstdio>

int main() {
  int T, a, b, c, n;
  scanf("%d", &T);
  while (T--) {
    n = 0;
    scanf("%d%d%d", &a, &b, &c);
    for (int i = 1; i <= a; i++)
      for (int j = i; j <= b; j++)
        for (int k = j; k <= c; k++)
          n += i % j == j % k  && j % k == k % i;
    printf("%d\n", n);
  }
}