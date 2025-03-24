#include <algorithm>
#include <cstdio>

int arr[50];

int main() {
  int n, lph;
  scanf("%d%d", &n, &lph);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

  int i = 0, m = 5 * lph;
  std::sort(arr, arr + n);
  for (i = 0; i < n; i++) {
    if (m >= arr[i])
      m -= arr[i];
    else
      break;
  }
  printf("%d", i);
}