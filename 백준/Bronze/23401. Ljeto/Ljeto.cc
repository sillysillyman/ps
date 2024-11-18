#include <cstdio>

int score[2], pineapple[4], blueberry[4];

int main() {
  int n;

  scanf("%d", &n);
  while (n--) {
    int t, a;

    scanf("%d%d%*d", &t, &a);
    if (a < 5) {
      --a;
      score[0] += (pineapple[a] && t - pineapple[a] <= 10) ? 150 : 100;
      pineapple[a] = t;
    } else {
      a -= 5;
      score[1] += (blueberry[a] && t - blueberry[a] <= 10) ? 150 : 100;
      blueberry[a] = t;
    }
  }
  printf("%d %d", score[0], score[1]);
}