#include <cstdio>

using ll = long long;

int main() {
  int N;
  ll sum = 0;

  scanf("%d", &N);
  for (int num, i = 0; i < N; i++) {
    scanf("%d", &num);
    sum += num;
  }
  printf("%d", sum - (ll)N * (N - 1) / 2);
}