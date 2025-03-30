#include <algorithm>
#include <cstdio>

int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};

int main() {
  int N;
  scanf("%d", &N);
  do {
    for (int i = 0; i < N; i++) printf("%d ", arr[i]);
    printf("\n");
  } while (std::next_permutation(arr, arr + N));
}