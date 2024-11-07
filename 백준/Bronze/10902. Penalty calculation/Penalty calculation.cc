#include <cstdio>

int main() {
  int n, f, t_f, s_f = -1;

  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int t, s;

    scanf("%d%d", &t, &s);
    if (s > s_f) {
      f = i;
      t_f = t;
      s_f = s;
    }
  }
  printf("%d", s_f ? t_f + (f - 1) * 20 : 0);
}