#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int N;

  while (scanf("%d", &N) && N) {
    vector<int> arr(N);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    for (int& i : arr) printf("%d ", i);
    printf("$\n");
  }
}