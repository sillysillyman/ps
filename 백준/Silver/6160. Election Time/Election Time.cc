#include <algorithm>
#include <cstdio>

using namespace std;

struct Vote {
  int f, s, i;
};

int main() {
  int N, K;
  Vote arr[50000];
  scanf("%d%d", &N, &K);
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &arr[i].f, &arr[i].s);
    arr[i].i = i + 1;
  }
  sort(arr, arr + N, [](auto &a, auto &b) { return a.f > b.f; });
  sort(arr, arr + K, [](auto &a, auto &b) { return a.s > b.s; });
  printf("%d", arr[0].i);
}