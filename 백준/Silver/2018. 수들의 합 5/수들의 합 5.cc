#include <cstdio>

int main() {
  int N, cnt = 0;

  scanf("%d", &N);

  int left = 0, right = 1;
  while (left <= right && right <= N) {
    if (int sum = (right - left + 1) * (left + right) / 2; sum == N) {
      ++cnt;
      ++left;
      ++right;
    } else if (sum < N)
      ++right;
    else if (sum > N)
      ++left;
  }
  printf("%d", cnt);
}