#include <cstdio>

int main() {
  int N;
  scanf("%d", &N);
  printf("%s", N & 1 ? "Either" : N / 2 & 1 ? "Odd" : "Even");
}