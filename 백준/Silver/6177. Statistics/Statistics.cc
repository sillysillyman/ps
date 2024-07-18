#include <algorithm>
#include <cstdio>
#include <numeric>

using namespace std;

int arr[500];

int main() {
  int N;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
  sort(arr, arr + N);
  printf("%.6f\n", (float)accumulate(arr, arr + N, 0) / N);
  if (N & 1)
    printf("%.6f\n", (float)arr[N / 2]);
  else
    printf("%.6f", (float)(arr[N / 2] + arr[N / 2 - 1]) / 2);
}