#include <iostream>

using namespace std;

int p[100'001];

int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

void unite(int x, int y) { p[find(x)] = find(y); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int G, P, cnt = 0;

  cin >> G >> P;
  for (int i = 1; i <= G; i++) p[i] = i;
  while (P--) {
    int g;

    cin >> g;
    g = find(g);
    if (!g) break;
    unite(g, g - 1);
    ++cnt;
  }
  cout << cnt;
}