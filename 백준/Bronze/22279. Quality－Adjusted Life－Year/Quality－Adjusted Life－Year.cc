#include <cstdio>

int N;
double q, y, QALY;

int main() {
  scanf("%d", &N);
  while (N--) {
    scanf("%lf%lf", &q, &y);
    QALY += q * y;
  }
  printf("%.3lf", QALY);
}