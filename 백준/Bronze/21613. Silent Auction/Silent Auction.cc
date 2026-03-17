#include <algorithm>
#include <cstdio>

int main() {
  int N;
  int arr[100];
  char s[100][9];
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%s%d", s[i], &arr[i]);
  printf("%s", s[std::max_element(arr, arr + N) - arr]);
}