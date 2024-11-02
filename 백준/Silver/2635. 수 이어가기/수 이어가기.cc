#include <cstdio>

int main() {
  int n, max_cnt = 0, second;
  int prev, curr, next;

  scanf("%d", &n);
  for (int i = 0; i <= n; i++) {
    int cnt = 2;

    prev = n;
    curr = i;
    while (true) {
      next = prev - curr;
      if (next < 0) break;
      ++cnt;
      prev = curr;
      curr = next;
    }
    if (cnt > max_cnt) {
      max_cnt = cnt;
      second = i;
    }
  }
  printf("%d\n%d %d ", max_cnt, n, second);
  prev = n;
  curr = second;
  while (true) {
    next = prev - curr;
    if (next < 0) break;
    printf("%d ", next);
    prev = curr;
    curr = next;
  }
}