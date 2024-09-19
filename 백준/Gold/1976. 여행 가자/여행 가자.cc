#include <cstdio>

int p[201];

int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

void unite(int x, int y) { p[find(x)] = find(y); }

int main() {
  int N, M, first_city;

  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++) p[i] = i;
  for (int i = 1; i <= N; i++) {
    for (int connected, j = 1; j <= N; j++) {
      scanf("%d", &connected);
      if (connected) unite(i, j);
    }
  }
  scanf("%d", &first_city);
  for (int city, i = 1; i < M; i++) {
    scanf("%d", &city);
    if (find(city) != find(first_city)) return puts("NO"), 0;
  }
  puts("YES");
}