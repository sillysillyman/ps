#include <cstdio>

int scores[101];
int arr[100'000];

int main() {
  int n;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    ++scores[arr[i]];
  }
  for (int tmp, rank = 1, i = 100; i >= 0; i--) {
    tmp = scores[i];
    if (scores[i]) scores[i] = rank;
    rank += tmp;
  }
  for (int i = 0; i < n; i++) printf("%d\n", scores[arr[i]]);
}