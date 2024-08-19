#include <cstdio>

const double PI = 3.14159;

int main() {
  int n;
  double max_volume = 0;

  scanf("%d", &n);
  while (n--) {
    char figure;

    scanf(" %c", &figure);
    if (figure == 'S') {
      double r;

      scanf("%lf", &r);
      if (double v = (4.0 / 3) * PI * r * r * r; v > max_volume) max_volume = v;
    } else {
      double r, h;

      scanf("%lf %lf", &r, &h);
      if (figure == 'C') {
        if (double v = (1.0 / 3) * PI * r * r * h; v > max_volume)
          max_volume = v;
      } else if (figure == 'L') {
        if (double v = PI * r * r * h; v > max_volume) max_volume = v;
      }
    }
  }
  printf("%.3lf", max_volume);
}