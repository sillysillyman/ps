#include <cstdio>

int main() {
  int w, l, h;
  scanf("%d%d%d", &w, &l, &h);
  if (l < w) w ^= l ^= w ^= l;
  printf(1. * w / h >= 2 && 1. * l / w <= 2 ? "good" : "bad");
}