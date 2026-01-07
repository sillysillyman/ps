#include <cstdio>

int a[51];

int main() {
  int N, x;
  scanf("%d", &N);
  while (N--) {
    scanf("%d", &x);
    a[x]++;
  }
  for (int i = 51; i >= 0; i--)
    if (i == a[i])
      return printf("%d", i), 0;
  printf("-1");
}