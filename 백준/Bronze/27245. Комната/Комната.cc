#include <cstdio>

int main() {
  int w, l, h;
  scanf("%d%d%d", &w, &l, &h);
  l < w ? w = l, l = w : 0;
  printf(1. * w / h >= 2 && 1. * l / w <= 2 ? "good" : "bad");
}