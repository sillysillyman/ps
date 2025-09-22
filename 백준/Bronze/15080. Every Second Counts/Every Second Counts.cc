#include <cstdio>

int main() {
  int h1, h2, m1, m2, s1, s2, s;
  scanf("%d : %d : %d\n%d : %d : %d", &h1, &m1, &s1, &h2, &m2, &s2);
  s = 3600 * (h2 - h1) + 60 * (m2 - m1) + s2 - s1;
  if (s < 0) s += 86400;
  printf("%d", s);
}