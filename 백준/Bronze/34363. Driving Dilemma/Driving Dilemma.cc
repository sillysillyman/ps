#include <cstdio>

int main() {
  double S, D, T;
  scanf("%lf%lf%lf", &S, &D, &T);
  printf(22 * S * T / 15 > D ? "MADE IT" : "FAILED TEST");
}