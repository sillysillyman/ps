#include <cstdio>

int p[3'001];
int deg[3'001];

int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

void unite(int x, int y) { p[find(x)] = find(y); }

int main() {
  int V, E, odd = 0;

  scanf("%d%d", &V, &E);
  for (int i = 1; i <= V; i++) p[i] = i;
  while (E--) {
    int a, b;

    scanf("%d%d", &a, &b);
    ++deg[a], ++deg[b];
    unite(a, b);
  }
  for (int i = 1; i <= V; i++) {
    if (find(1) != find(i)) return puts("NO"), 0;
    if (deg[i] & 1) ++odd;
  }
  odd == 0 || odd == 2 ? puts("YES") : puts("NO");
}