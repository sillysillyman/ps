#include <cstdio>

int N;
double q, y, s;

int main() {
  scanf("%d", &N);
  while (N--) {
    scanf("%lf%lf", &q, &y);
    s += q * y;
  }
  printf("%.3lf", s);
}