#include <cstdio>

int N;
long long sum;
int arr[1'000];

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int num, j = 0; j < N; j++) {
      scanf("%d", &num);
      arr[i] += num;
    }
    sum += arr[i];
  }

  if (N == 2) return printf("%d %d", arr[0] / 2, arr[0] / 2), 0;

  sum /= 2 * (N - 1);
  for (int i = 0; i < N; i++) printf("%lld ", (arr[i] - sum) / (N - 2));
}