#include <algorithm>
#include <cstdio>

long long arr[10'000];

int main() {
  int n;
  long long sum =0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
  std::sort(arr, arr + n, std::greater());
  for (int i = 0; i < n; i++) sum += (n - 2 * i - 1) * arr[i];
  printf("%lld", 2 * sum);
}