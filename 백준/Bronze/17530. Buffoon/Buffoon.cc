#include <cstdio>

int main() {
  int N, M, V, v;
  scanf("%d%d", &N, &V);
  M = V;
  while (--N) {
    scanf("%d", &v);
    if (v > M) M = v;
  }
  printf(M == V ? "S" : "N");
}