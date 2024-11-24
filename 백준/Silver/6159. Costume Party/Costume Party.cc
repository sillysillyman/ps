#include <algorithm>
#include <cstdio>

int N, S, cnt;
int arr[20'000];

int main() {
  scanf("%d%d", &N, &S);
  for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
  std::sort(arr, arr + N);

  int left = 0, right = N - 1;
  while (left < right) {
    if (arr[left] + arr[right] <= S) {
      cnt += right - left;
      ++left;
    } else
      --right;
  }
  printf("%d", cnt);
}