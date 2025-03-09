#include <algorithm>
#include <cstdio>

using namespace std;

int arr[1'000];

int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

  sort(arr, arr + N);
  for (int i = 0; i < N - 1; i++) {
    if (arr[i] + 1 == arr[i + 1]) {
      int j = i + 2;
      while (j != N && arr[j] == arr[i + 1]) ++j;

      if (j != N)
        swap(arr[j], arr[i + 1]);
      else {
        int k = i - 1;
        while (k >= 0 && arr[k] == arr[i]) --k;

        ++arr[k + 1];
        --arr[i + 1];
      }
    }
  }

  for (int i = 0; i < N; i++) printf("%d ", arr[i]);
}