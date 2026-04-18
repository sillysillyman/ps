#include <cstdio>

int x, c, N = 10;
int arr[5];

int main() {
  while (N--) {
    scanf("%d", &x);
    arr[x]++;
  }
  for (int i = 1; i < 5; i++) c += !arr[i];
  printf("%d", c);
}