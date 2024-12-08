#include <algorithm>
#include <cstdio>

int N, x, y, score;

int main() {
  scanf("%d%d", &N, &x);
  while (--N) {
    scanf("%d", &y);
    score += x * y;
    x += y;
  }
  printf("%d", score);
}