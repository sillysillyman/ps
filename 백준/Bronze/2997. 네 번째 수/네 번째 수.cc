#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
  int arr[3];

  scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);
  sort(arr, arr + 3);
  printf("%d", arr[1] - arr[0] > arr[2] - arr[1]   ? 2 * arr[1] - arr[2]
               : arr[2] - arr[1] > arr[1] - arr[0] ? 2 * arr[1] - arr[0]
                                                   : 2 * arr[2] - arr[1]);
}