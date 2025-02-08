#include <cmath>
#include <cstdio>

int main() {
  int n;
  while (scanf("%d", &n) && n) {
    int team, min_diff = 1e4;
    for (int score, diff, i = 1; i <= n; i++) {
      scanf("%d", &score);
      diff = abs(score - 2023);
      if (diff < min_diff) min_diff = diff, team = i;
    }
    printf("%d\n", team);
  }
}