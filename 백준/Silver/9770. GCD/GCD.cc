#include <algorithm>
#include <cstdio>
#include <numeric>

int arr[100];

int main() {
  int idx = 0;
  while (~scanf("%d", &arr[idx])) ++idx;

  int max_gcd = 0;
  for (int i = 0; i < idx - 1; i++)
    for (int j = i + 1; j < idx; j++)
      max_gcd = std::max(max_gcd, std::gcd(arr[i], arr[j]));
  printf("%d", max_gcd);
}