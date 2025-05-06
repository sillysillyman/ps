#include <algorithm>
#include <cstdio>
#include <numeric>

using namespace std;

int arr[50];

int main() {
  int N, L, H;
  scanf("%d%d%d", &N, &L, &H);
  for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

  sort(arr, arr + N);
  printf("%.9lf", accumulate(arr + L, arr + N - H, 0) / (double)(N - L - H));
}