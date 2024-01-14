#include <iostream>

using namespace std;

int parents[1000001];

int find(int x) {
  if (parents[x] == x) return x;
  else return parents[x] = find(parents[x]);
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (x < y) parents[y] = x;
  else parents[x] = y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;

  cin >> n >> m;
  for (int i = 0; i <= n; i++) parents[i] = i;
  while (m--) {
    // for (int i = 0; i <= n; i++) cout << i << " ";
    // cout << '\n';
    // for (int i = 0; i <= n; i++) cout << parents[i] << ' ';
    // cout << '\n';
    // cout << '\n';
    int cmd, a, b;

    cin >> cmd >> a >> b;
    if (cmd == 0) merge(a, b);
    else if (cmd == 1) {
      if (find(a) == find(b)) cout << "YES\n";
      else cout << "NO\n";
    }
  }
}