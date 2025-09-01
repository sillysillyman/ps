#include <cstdio>

int main() {
  int x;
  int arr[4];
  for (int i = 0; i < 4; i++) scanf("%d", &arr[i]);
  scanf("%d%*d%*d", &x);
  for (int i = 0; i < 4; i++) if (arr[i] == x) return printf("%d", i + 1), 0;
  printf("0");
}