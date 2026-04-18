#include <cstdio>

int main() {
  int x, c = 0, N = 10;
  int arr[5] = {};
  while (N--) {
    scanf("%d", &x);
    arr[x]++;
  }
  for (int i = 1; i < 5; i++) c += !arr[i];
  printf("%d", c);
}