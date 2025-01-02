#include <algorithm>
#include <cstdio>

int arr[4];

bool is_terminated() {
  return (arr[0] && !arr[1] && !arr[2] && !arr[3]) ||
         (!arr[0] && arr[1] && !arr[2] && !arr[3]) ||
         (!arr[0] && !arr[1] && arr[2] && !arr[3]) ||
         (!arr[0] && !arr[1] && !arr[2] && arr[3]);
}

std::pair<int, int> calc_min() {
  int min_idx = -1;
  int min_val = 101;

  for (int i = 0; i < 4; i++)
    if (arr[i] && arr[i] < min_val) min_idx = i, min_val = arr[i];

  return {min_idx, min_val};
}

int main() {
  while (scanf("%d%d%d%d", &arr[0], &arr[1], &arr[2], &arr[3]) &&
         (arr[0] || arr[1] || arr[2] || arr[3])) {
    while (!is_terminated()) {
      auto [min_idx, min_val] = calc_min();
      for (int i = 0; i < 4; i++)
        if (arr[i] && i != min_idx) arr[i] -= min_val;
    }

    printf("%d\n", *std::max_element(arr, arr + 4));
  }
}