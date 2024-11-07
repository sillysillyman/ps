#include <cstdio>

int main() {
  int n, f, s_f = -1, t_f;

  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int t, s;

    scanf("%d%d", &t, &s);
    if (s > s_f) {
      f = i;
      s_f = s;
      t_f = t;
    }
  }
  printf("%d", s_f ? t_f + (f - 1) * 20 : 0);
}