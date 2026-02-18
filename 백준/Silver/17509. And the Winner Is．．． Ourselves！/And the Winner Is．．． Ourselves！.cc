#include <algorithm>
#include <cstdio>

int main() {
  int N = 0;
  int arr[11];
  for (int V, i = 0; i < 11; i++) {
    scanf("%d%d", &arr[i], &V);
    N += 20 * V;
  }
  std::sort(arr, arr + 11);
  for (int i = 0; i < 11; i++) N += (11 - i) * arr[i];
  printf("%d", N);
}