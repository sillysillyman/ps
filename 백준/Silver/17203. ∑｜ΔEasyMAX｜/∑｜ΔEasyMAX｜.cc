#include <cmath>
#include <cstdio>

using namespace std;

int arr[1'000];

int main() {
  int N, Q;

  scanf("%d %d", &N, &Q);
  for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
  while (Q--) {
    int start, end, sum = 0;

    scanf("%d %d", &start, &end);
    for (int i = start - 1; i < end - 1; i++) sum += abs(arr[i + 1] - arr[i]);
    printf("%d\n", sum);
  }
}