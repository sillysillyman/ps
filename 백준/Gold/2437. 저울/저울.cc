#include <algorithm>
#include <cstdio>

int N, s;
int arr[1000];

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
  std::sort(arr, arr + N);
  for (int i = 0; i < N; i++) {
    if (s + 1 < arr[i]) return printf("%d", ++s), 0;
    else s += arr[i];
  }
  printf("%d", ++s);
}