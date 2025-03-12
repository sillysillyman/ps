#include <cstdio>

int arr[50];

int main() {
  int N;
  long long cluster, cnt = 0;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
  scanf("%lld", &cluster);

  for (int i = 0; i < N; i++) cnt += arr[i] / cluster + !!(arr[i] % cluster);

  printf("%lld", cluster * cnt);
}