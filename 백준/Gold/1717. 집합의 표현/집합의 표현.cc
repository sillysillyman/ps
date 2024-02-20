#include <iostream>

using namespace std;

int parents[1'000'001];

int find(int x) {
  if (parents[x] == x) return x;
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

  int n, m;

  cin >> n >> m;
  for (int i = 0; i <= n; i++) parents[i] = i;
  while (m--) {
    int cmd, a, b;

    cin >> cmd >> a >> b;
    if (cmd == 0)
      merge(a, b);
    else if (cmd == 1) {
      if (find(a) == find(b))
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
}