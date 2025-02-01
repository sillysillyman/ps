#include <cstdio>

int arr[50];

int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

  if (N == 1)
    printf("A");
  else if (N == 2) {
    if (arr[0] == arr[1])
      printf("%d", arr[0]);
    else
      printf("A");
  } else {
    if (arr[0] == arr[1]) {
      for (int i = 0; i < N; i++)
        if (arr[i] != arr[0]) return printf("B"), 0;
      return printf("%d", arr[0]), 0;
    }
    
    int a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
    int b = arr[1] - a * arr[0];

    for (int i = 1; i < N; i++)
      if (arr[i] != a * arr[i - 1] + b) return printf("B"), 0;

    printf("%d", a * arr[N - 1] + b);
  }
}