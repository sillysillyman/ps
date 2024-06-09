#include <algorithm>
#include <cstdio>

int frequencies[5];

int main() {
  int A, B, N;

  scanf("%d %d", &A, &B);
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &frequencies[i]);

  int min_cnt = abs(A - B);

  for (int i = 0; i < N; i++)
    min_cnt = std::min(min_cnt, abs(B - frequencies[i]) + 1);
  printf("%d", min_cnt);
}