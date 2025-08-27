#include <cstdio>

int main() {
  int n, w, h, f;
  scanf("%d", &n);
  while (n--) {
    scanf("%d%d%d", &w, &h, &f);
    printf("Data set: %d %d %d\n", w, h, f);
    while (f--) w > h ? w /= 2 : h /= 2;
    printf("%d %d\n\n", w > h ? w : h, w < h ? w : h);
  }
}