#include <cstdio>

int arr[100'001];

int main() {
  int N, M;
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &arr[i]);
    arr[i] += arr[i - 1];
  }
  scanf("%d", &M);
  while (M--) {
    int i, j;
    scanf("%d%d", &i, &j);
    printf("%d\n", arr[j] - arr[i - 1]);
  }
}