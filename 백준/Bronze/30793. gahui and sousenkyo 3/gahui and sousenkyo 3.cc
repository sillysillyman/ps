#include <cstdio>

int main() {
  int p, r;
  scanf("%d%d", &p, &r);
  double v = 1. * p / r;
  printf(v < 0.2 ? "weak" : v < 0.4 ? "normal" : v < 0.6 ? "strong" : "very strong");
}