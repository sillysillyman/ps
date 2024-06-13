#include <cstdio>

int main() {
  int N;

  scanf("%d", &N);

  int cnt = ~-N / 9 + 1;
  printf("%d", cnt + (!(cnt & 1) * N & 1));
}