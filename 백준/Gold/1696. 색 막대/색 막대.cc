#include <cstdio>
#include <map>

using namespace std;
using ll = long long;

char c1[11], c2[11];
int p[500'000], deg[500'000];
map<ll, int> m;

int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

void unite(int x, int y) { p[find(x)] = find(y); }

ll to_hash(char *s) {
  ll h = 0;
  for (int i = 0; s[i]; i++) h = h * 31 + s[i];
  return h;
}

int main() {
  for (int i = 0; i < 500'000; i++) p[i] = i;

  int x, y, odd = 0, idx = 0;

  while (~scanf("%s %s", c1, c2)) {
    ll h1 = to_hash(c1), h2 = to_hash(c2);
    if (m.find(h1) == m.end()) m[h1] = idx++;
    if (m.find(h2) == m.end()) m[h2] = idx++;
    x = m[h1], y = m[h2];
    deg[x]++, deg[y]++;
    unite(x, y);
  }
  for (int i = 0; i < idx; i++)
    if (deg[i] & 1) ++odd;
  for (int i = 0; i < idx; i++)
    if (find(i) != find(0)) return puts("Impossible"), 0;
  puts(odd == 0 || odd == 2 ? "Possible" : "Impossible");
}