#include <cstdio>
#include <map>

using namespace std;

int p[2'000], deg[2'000];

int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

void unite(int x, int y) { p[find(x)] = find(y); }

int main() {
  int N;

  while (scanf("%d", &N) && N) {
    int a, b, c, d, idx = 0, odd = 0;
    map<pair<int, int>, int> m;

    fill(deg, deg + 2 * N, 0);
    for (int i = 0; i < 2 * N; i++) p[i] = i;
    while (N--) {
      scanf("%d%d%d%d", &a, &b, &c, &d);
      if (m.find({a, b}) == m.end()) m[{a, b}] = idx++;
      if (m.find({c, d}) == m.end()) m[{c, d}] = idx++;
      ++deg[m[{a, b}]], ++deg[m[{c, d}]];
      unite(m[{a, b}], m[{c, d}]);
    }

    bool flag = false;
    for (int i = 0; i < idx; i++) {
      if (find(0) != find(i)) {
        puts("Impossible");
        flag = true;
        break;
      }
      if (deg[i] & 1) ++odd;
    }
    if (flag) continue;
    odd == 0 || odd == 2 ? puts("Possible") : puts("Impossible");
  }
}