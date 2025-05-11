#include <cmath>
#include <cstdio>

int arr[5];

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) scanf("%d", &arr[i]);
  printf("%d", 4763 * (abs((arr[0] - arr[2])) * (arr[0] > arr[2] ? 508 : 108) +
                       abs(arr[1] - arr[3]) * (arr[1] > arr[3] ? 212 : 305) +
                       707 * arr[4]));
}