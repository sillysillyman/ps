#include <cstdio>

int main() {
  int N, m;
  double p[4];

  scanf("%d%d", &N, &m);
  for (int i = 0; i < 4; i++) scanf("%lf", &p[i]);

  double g = !m, b = m;
  for (int i = 0; i < N; i++) {
    double prev_g = g;
    g = g * p[0] + b * p[2];
    b = prev_g * p[1] + b * p[3];
  }
  printf("%d\n%d", int(1000 * g), int(1000 * b));
}