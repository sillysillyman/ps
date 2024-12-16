#include <cstdio>

int main() {
  int N, mood;
  double probability[4];

  scanf("%d%d", &N, &mood);
  for (int i = 0; i < 4; i++) scanf("%lf", &probability[i]);

  double good = !mood, bad = mood;
  for (int i = 0; i < N; i++) {
    double prev_good = good;
    good = good * probability[0] + bad * probability[2];
    bad = prev_good * probability[1] + bad * probability[3];
  }
  printf("%d\n%d", int(1000 * good), int(1000 * bad));
}