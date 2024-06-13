#include <cstdio>

int main() {
  int N;

  scanf("%d", &N);

  if (int cnt = (N - 1) / 9 + 1; !(cnt & 1) && N & 1)
    printf("%d", cnt + 1);
  else
    printf("%d", cnt);
}