#include <algorithm>
#include <cstdio>

int N, score;
int arr[100];

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
  std::sort(arr, arr + N);
  for (int size = arr[0], i = 1; i < N; i++) {
    score += size * arr[i];
    size += arr[i];
  }
  printf("%d", score);
}