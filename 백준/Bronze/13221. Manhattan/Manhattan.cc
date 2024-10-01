#include <math.h>

#include <cstdio>

int main() {
  int taxi_x, taxi_y, N, min_x = 100, min_y = 100;

  scanf("%d%d%d", &taxi_x, &taxi_y, &N);
  while (N--) {
    int x, y;

    scanf("%d%d", &x, &y);
    if (abs(x - taxi_x) + abs(y - taxi_y) <
        abs(min_x - taxi_x) + abs(min_y - taxi_y))
      min_x = x, min_y = y;
  }
  printf("%d %d", min_x, min_y);
}