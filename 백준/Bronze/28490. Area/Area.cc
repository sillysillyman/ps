#include <cstdio>

int main() {
  int n, area = 0;
  scanf("%d", &n);
  while (n--) {
    int h, w;
    scanf("%d%d", &h, &w);
    if (h * w > area) area = h * w;
  }
  printf("%d", area);
}