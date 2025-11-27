#include <cstdio>

int main() {
  long long X1, X2, Y1, Y2, R1, R2;
  scanf("%lld%lld%lld%lld%lld%lld", &X1, &Y1, &R1, &X2, &Y2, &R2);
  printf((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2) < (R1 + R2) * (R1 + R2) ? "YES" : "NO");
}