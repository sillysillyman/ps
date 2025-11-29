#include <cstdio>

int n, x, f, m;
int arr[201];

int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &x);
    arr[x] = 1;
    if (x > m) m = x;
  }
  for (int i = 1; i <= m; i++) {
    if (!arr[i]) {
      f = 1;
      printf("%d\n", i);
    }
  }
  if (!f) printf("good job");
}