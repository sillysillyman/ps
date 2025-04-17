#include <algorithm>
#include <cstdio>
#include <numeric>

using namespace std;

int N, max_idx, global_max;

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    int arr[5];
    for (int j = 0; j < 5; j++) scanf("%d", &arr[j]);
    sort(arr, arr + 5);

    int local_max = 0;
    do local_max = max(local_max, accumulate(arr, arr + 3, 0) % 10);
    while (next_permutation(arr, arr + 5));

    if (local_max >= global_max) {
      max_idx = i;
      global_max = local_max;
    }
  }

  printf("%d", max_idx);
}