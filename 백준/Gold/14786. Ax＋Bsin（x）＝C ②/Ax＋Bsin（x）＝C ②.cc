#include <cmath>
#include <cstdio>

const double e = 1e-9;

int main() {
  int A, B, C;
  scanf("%d%d%d", &A, &B, &C);

  double curr = 0, next;
  while (fabs(A * curr + B * sin(curr) - C) > e) {
    next = curr - (A * curr + B * sin(curr) - C) / (A + B * cos(curr));
    curr = next;
  }
  printf("%.9lf\n", curr);
}