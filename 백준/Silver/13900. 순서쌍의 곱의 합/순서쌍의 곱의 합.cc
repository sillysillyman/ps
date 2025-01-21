#include <cstdio>

long long arr[100'001];

int main() {
  int N;
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%lld", &arr[i]);
    arr[i] += arr[i - 1];
  }

  long long sum = 0;
  for (int i = 1; i <= N; i++) sum += (arr[i] - arr[i - 1]) * (arr[N] - arr[i]);
  printf("%lld", sum);
}