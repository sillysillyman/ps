#include <cstdio>

int main() {
  int p, r;
  scanf("%d%d", &p, &r);
  double v = 1. * p / r;
  printf(v < .2 ? "weak" : v < .4 ? "normal" : v < .6 ? "strong" : "very strong");
}