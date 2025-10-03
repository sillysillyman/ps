#include <cstdio>

int main() {
  int N, C, P;
  scanf("%d%d%d", &N, &C, &P);
  printf(N > C * P ? "no" : "yes");
}