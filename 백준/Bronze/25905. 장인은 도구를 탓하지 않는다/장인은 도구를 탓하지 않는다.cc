#include <algorithm>
#include <cstdio>

int main() {
  double arr[10];
  for (int i = 0; i < 10; i++) scanf("%lf", &arr[i]);
  std::sort(arr, arr + 10, [](auto a, auto b) { return a > b; });
  double p = 1e9;
  for (int i = 0; i < 9; i++) p *= arr[i] / (i + 1);
  printf("%lf", p);
}