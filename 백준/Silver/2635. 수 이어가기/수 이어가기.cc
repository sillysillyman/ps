#include <cstdio>

int main() {
  int n, max_cnt = 0, second;

  scanf("%d", &n);
  for (int i = n / 2; i <= n; ++i) {
    int cnt = 2;
    int prev = n, curr = i;
    while (prev >= curr) {
      int next = prev - curr;
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
  int prev = n, curr = second;
  while (prev >= curr) {
    int next = prev - curr;
    printf("%d ", next);
    prev = curr;
    curr = next;
  }
}