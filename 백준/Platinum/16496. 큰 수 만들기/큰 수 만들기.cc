#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

int arr[1'000];

int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

  sort(arr, arr + N, [](const int &a, const int &b) {
    string str_a = to_string(a), str_b = to_string(b);
    return str_a + str_b > str_b + str_a;
  });

  if (!arr[0]) return printf("0"), 0;
  for (int i = 0; i < N; i++) printf("%d", arr[i]);
}