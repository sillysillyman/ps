#include <cstdio>

int main() {
  int N;
  int arr[100];
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
  printf("%d", arr[N - 1] + arr[1] - arr[0]);
}