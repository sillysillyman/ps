#include <cmath>
#include <cstdio>

int main() {
  double A, R, P1, P2;

  scanf("%lf%lf%lf%lf", &A, &P1, &R, &P2);
  printf("%s", A / P1 > R * R * M_PI / P2 ? "Slice of pizza" : "Whole pizza");
}