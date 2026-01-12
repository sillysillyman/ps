#include <algorithm>
#include <cstdio>

int main() {
  double arr[10];
  for (int i = 0; i < 10; i++) scanf("%lf", &arr[i]);
  std::sort(arr, arr + 10);
  double p = 1e9 / 362880;
  for (int i = 1; i < 10; i++) p *= arr[i];
  printf("%lf", p);
}