#include <iostream>

using namespace std;

const int MAX = 500'000;
int parents[MAX];

int find(int x) {
  if (x == parents[x]) return x;
  return parents[x] = find(parents[x]);
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (x < y)
    parents[y] = x;
  else
    parents[x] = y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  bool has_cycle = false;
  int n, m;
  int order = 0;

  cin >> n >> m;
  for (int i = 0; i < n; i++) parents[i] = i;
  for (int p, q, i = 1; i <= m; i++) {
    cin >> p >> q;
    if (has_cycle) continue;
    if (find(p) == find(q)) {
      has_cycle = true;
      order = i;
    }
    merge(p, q);
  }
  cout << order;
}