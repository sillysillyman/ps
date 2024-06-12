#include <cstdio>

int main() {
  int N, total_time = 0;

  scanf("%d", &N);
  total_time += 8 * (N - 1);
  while (N--) {
    int time;

    scanf("%d", &time);
    total_time += time;
  }
  printf("%d %d", total_time / 24, total_time % 24);
}