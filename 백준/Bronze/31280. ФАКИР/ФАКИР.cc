#include <algorithm>
#include <cstdio>

int arr[4];

int main() {
  for (int i = 0; i < 4; i++) scanf("%d", &arr[i]);
  std::sort(arr, arr + 4);
  printf("%d", arr[1] + arr[2] + arr[3] + 1);
}