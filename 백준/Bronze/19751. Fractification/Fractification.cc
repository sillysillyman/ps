#include <algorithm>
#include <cstdio>

int main() {
  int arr[4];
  scanf("%d%d%d%d", arr, arr + 1, arr + 2, arr + 3);
  std::sort(arr, arr + 4);
  printf("%d %d %d %d", arr[0], arr[2], arr[1], arr[3]);
}