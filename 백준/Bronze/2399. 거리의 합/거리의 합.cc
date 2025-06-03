#include <cmath>
#include <cstdio>

int arr[10'000];

int main() {
  int n;
  long long sum =0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) sum += abs(arr[i] - arr[j]);
  printf("%lld", sum);
}