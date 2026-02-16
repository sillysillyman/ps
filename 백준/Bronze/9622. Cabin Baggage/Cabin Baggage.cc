#include <cstdio>

int main() {
  int t, f, c = 0;
  double l, w, d, m;
  scanf("%d", &t);
  while (t--) {
    scanf("%lf%lf%lf%lf", &l, &w, &d, &m);
    f = (l <= 56 && w <= 45 && d <= 25 || l + w + d <= 125) && m <= 7;
    c += f;
    printf("%d\n", f);
  }
  printf("%d", c);
}