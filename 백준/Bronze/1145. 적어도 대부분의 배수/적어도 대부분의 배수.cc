#include <algorithm>
#include <cstdio>
#include <numeric>

using namespace std;

int arr[5];

int main() {
  int min_multiple = 1'000'000;

  for (int i = 0; i < 5; i++) scanf("%d", &arr[i]);
  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 4; j++) {
      for (int k = j + 1; k < 5; k++)
        min_multiple = min(min_multiple, lcm(arr[i], lcm(arr[j], arr[k])));
    }
  }
  printf("%d", min_multiple);
}