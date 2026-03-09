#include <cstdio>

int main() {
  int N, K, c = 0;
  scanf("%d%d", &N, &K);
  while (N--) {
    char b;
    scanf(" %c", &b);
    b - '0' == 1 ? c = 0: c++;
    if (c >= K) return printf("0"), 0;
  }
  printf("1");
}