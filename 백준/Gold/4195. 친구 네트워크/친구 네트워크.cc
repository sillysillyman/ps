#include <iostream>
#include <unordered_map>

using namespace std;

const int MAX = 200'000;
int parents[MAX + 1];
int cnts[MAX + 1];
unordered_map<string, int> idxs;

int find(int x) {
  if (x == parents[x]) return x;
  return parents[x] = find(parents[x]);
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (x < y) {
    parents[y] = x;
    cnts[x] += cnts[y];
  } else {
    parents[x] = y;
    cnts[y] += cnts[x];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;

  cin >> T;
  while (T--) {
    int F;
    int idx = 1;
    string a, b;

    idxs.clear();
    cin >> F;
    for (int i = 0; i < F; i++) {
      int cnt = 0;

      cin >> a >> b;
      if (!idxs[a]) {
        idxs[a] = idx;
        parents[idx] = idx;
        cnts[idx] = 1;
        idx++;
      }
      if (!idxs[b]) {
        idxs[b] = idx;
        parents[idx] = idx;
        cnts[idx] = 1;
        idx++;
      }
      merge(idxs[a], idxs[b]);
      cout << cnts[find(idxs[a])] << '\n';
    }
  }
}