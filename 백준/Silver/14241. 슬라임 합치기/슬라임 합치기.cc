#include <algorithm>
#include <cstdio>

int N, size, score;
int arr[100];

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
  std::sort(arr, arr + N);
  size = arr[0] + arr[1];
  score += arr[0] * arr[1];
  for (int i = 2; i < N; i++) {
    score += size * arr[i];
    size += arr[i];
  }
  printf("%d", score);
}