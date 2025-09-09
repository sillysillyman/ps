#include <cstdio>

int n, x, y, s;
bool arr[1000];

int main() {
  scanf("%d", &n);
  for (int b, i = 0; i < n; i++) scanf("%d", &b), arr[i] = b;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x, &y);
    s += y > x && arr[i] ? y - x : 0;
  }
  printf("%d", s);
}