#include <cstdio>

int days[11] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

int main() {
  int x, y, day = 0;

  scanf("%d %d", &x, &y);
  day += y;
  for (int i = 0; i < x - 1; i++) day += days[i];
  printf("%s", (const char*[]){"SUN", "MON", "TUE", "WED", "THU", "FRI",
                               "SAT"}[day % 7]);
}