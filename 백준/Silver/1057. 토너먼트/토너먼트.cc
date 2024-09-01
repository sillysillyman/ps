#include <cstdio>

int N, a, b, round;

int main() {
  scanf("%d%d%d", &N, &a, &b);
  while (a != b) {
    a = (a & 1 ? ++a : a) / 2;
    b = (b & 1 ? ++b : b) / 2;
    ++round;
  }
  printf("%d", round);
}