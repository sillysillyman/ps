#include <cstdio>

int main() {
  int w, l, h;
  scanf("%d%d%d", &w, &l, &h);
  if (l < w) w ^= l ^= w ^= l;
  printf(2 * h <= w && l <= 2 * w ? "good" : "bad");
}