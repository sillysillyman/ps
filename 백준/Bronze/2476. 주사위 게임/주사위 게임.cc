#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
  int N;
  int arr[1000];
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    arr[i] = a == b && b == c             ? 1000 * (10 + a)
             : a != b && b != c && c != a ? 100 * max({a, b, c})
                                          : 1000 + 100 * (a == b   ? a
                                                          : b == c ? b
                                                                   : c);
  }
  sort(arr, arr + N);
  printf("%d", arr[N - 1]);
}