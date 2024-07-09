#include <cstdio>

int main() {
  int t = 0;

  while (++t) {
    int L, P, V;

    scanf("%d %d %d", &L, &P, &V);
    if (L == 0) break;
    printf("Case %d: %d\n", t, L * (V / P) + (L < V % P ? L : V % P));
  }
}