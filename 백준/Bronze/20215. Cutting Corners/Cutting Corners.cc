#include <cmath>
#include <cstdio>

int main() {
  int w, h;
  scanf("%d%d", &w, &h);
  printf("%lf", w + h - hypot(w, h));
}