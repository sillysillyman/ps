#include <cstdio>

int N, cnt;

int main() {
  scanf("%d", &N);
  for (int i = 1; i * (i - 1) / 2 < N; i++)
    cnt += !((N - i * (i - 1) / 2) % i);
  printf("%d", cnt);
}