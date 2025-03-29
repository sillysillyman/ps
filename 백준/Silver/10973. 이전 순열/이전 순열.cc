#include <algorithm>
#include <cstdio>

int arr[10'000];

int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

  if (!std::prev_permutation(arr, arr + N))
    printf("-1");
  else
    for (int i = 0; i < N; i++) printf("%d ", arr[i]);
}