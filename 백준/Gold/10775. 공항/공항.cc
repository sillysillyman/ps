#include <cstdio>

int p[100'001];

int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

void unite(int x, int y) { p[find(x)] = find(y); }

int main() {
  int G, P, cnt = 0;

  scanf("%d%d", &G, &P);
  for (int i = 1; i <= G; i++) p[i] = i;
  while (P--) {
    int g;

    scanf("%d", &g);
    g = find(g);
    if (!g) break;
    unite(g, g - 1);
    ++cnt;
  }
  printf("%d", cnt);
}