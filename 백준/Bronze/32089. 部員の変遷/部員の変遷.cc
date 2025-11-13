#include <cstdio>

int main() {
  int n, a, m, s;
  int arr[1000];
  while (scanf("%d", &n) && n) {
    m = 0;
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (int i = 2; i < n; i++) s = arr[i - 2] + arr[i - 1] + arr[i], m = m > s ? m : s;
    printf("%d\n", m);
  }
}