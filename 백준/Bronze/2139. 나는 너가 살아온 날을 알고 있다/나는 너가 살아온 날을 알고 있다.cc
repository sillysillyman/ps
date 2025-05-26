#include <cstdio>

int main() {
  int d, m, y;
  while (scanf("%d%d%d", &d, &m, &y) && (d || m || y)) {
    int cnt = 0;
    bool flag = !(y % 4) && (y % 100) || !(y % 400);
    for (int i = 1; i < m; i++) {
      if (i == 2)
        cnt += 28 + flag;
      else
        cnt += i < 8 ? (i & 1 ? 31 : 30) : (i & 1 ? 30 : 31);
    }
    printf("%d\n", cnt + d);
  }
}