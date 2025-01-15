#include <cstdio>

int N, cnt;

int main() {
  scanf("%d", &N);
  for (int i = 1; i * (i - 1) / 2 < N; i++)
    if (!((N - i * (i - 1) / 2) % i)) ++cnt;
  printf("%d", cnt);
}