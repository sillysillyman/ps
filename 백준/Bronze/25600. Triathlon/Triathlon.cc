#include <cstdio>

int main() {
  int N;
  scanf("%d", &N);

  int max_score = 0;
  while (N--) {
    int a, d, g;
    scanf("%d%d%d", &a, &d, &g);

    if (int score = a == d + g ? 2 * a * a : a * (d + g); score > max_score)
      max_score = score;
  }
  printf("%d", max_score);
}