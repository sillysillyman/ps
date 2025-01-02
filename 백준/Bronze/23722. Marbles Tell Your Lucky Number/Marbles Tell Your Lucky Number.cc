#include <cstdio>
#include <algorithm>

int arr[4];

int main() {
  while (scanf("%d%d%d%d", &arr[0], &arr[1], &arr[2], &arr[3]) &&
         (arr[0] || arr[1] || arr[2] || arr[3])) {
    int min_idx = -1;
    int min_val = 101;

    while ((arr[0] || arr[1] || arr[2]) && (arr[0] || arr[1] || arr[3]) &&
           (arr[0] || arr[2] || arr[3]) && (arr[1] || arr[2] || arr[3])) {
      for (int i = 0; i < 4; i++)
        if (arr[i] && arr[i] < min_val) min_idx = i, min_val = arr[i];
      for (int i = 0; i < 4; i++)
        if (arr[i] && min_idx != i) arr[i] -= min_val;
    }

    printf("%d\n", *std::max_element(arr, arr + 4));
  }
}