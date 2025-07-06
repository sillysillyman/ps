#include <cstdio>

int N, n;
int arr[34];

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &arr[i]);
    if (arr[i] - arr[i - 1] != 1) n += arr[i];
  }
  printf("%d", n);
}