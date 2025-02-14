#include <cstdio>

int n;

int main() {
  int arr[3];
  scanf("%d%d%d", arr, arr + 1, arr + 2);
  for (int x, i = 0; i < 3; i++) {
    scanf("%d", &x), arr[i] -= x;
    if (arr[i] < 0) n += -arr[i];
  }
  printf("%d", n);
}