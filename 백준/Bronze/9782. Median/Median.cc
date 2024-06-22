#include <cstdio>

int main() {
  int t = 0;

  while (true) {
    int n;
    float median;

    scanf("%d", &n);
    if (n == 0) break;
    for (int num, i = 0; i < n; i++) {
      scanf("%d", &num);
      if (n & 1 && i == n / 2)
        median = num;
      else if (i == n / 2 - 1)
        median = num;
      else if (i == n / 2)
        median = (median + num) / 2;
    }
    printf("Case %d: %.1f\n", ++t, median);
  }
}