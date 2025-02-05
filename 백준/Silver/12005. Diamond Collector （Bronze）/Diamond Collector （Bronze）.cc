#include <algorithm>
#include <cstdio>

int arr[1'000];

int main() {
  int N, K;
  scanf("%d%d", &N, &K);
  for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

  int cnt = 0;
  std::sort(arr, arr + N);
  for (int i = 0; i < N - 1; i++)
    for (int j = i + 1; j < N; j++)
      if (arr[j] - arr[i] <= K) cnt = std::max(cnt, j - i + 1);

  printf("%d", cnt);
}