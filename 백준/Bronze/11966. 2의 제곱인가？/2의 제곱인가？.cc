#include <cstdio>

int main() {
  int N;

  scanf("%d", &N);
  printf("%d", !(N & (N - 1)));
}