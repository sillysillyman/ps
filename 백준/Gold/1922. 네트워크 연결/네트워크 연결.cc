#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Info {
  int cost, u, v;

  bool operator<(const Info other) const { return cost < other.cost; }
};

int min_cost = 0;
int parents[1001];
vector<Info> infos;

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

  int N, M;

  cin >> N >> M;
  for (int i = 1; i <= N; i++) parents[i] = i;
  for (int i = 0; i < M; i++) {
    Info info;

    cin >> info.u >> info.v >> info.cost;
    infos.push_back(info);
  }
  sort(infos.begin(), infos.end());
  for (Info info : infos) {
    if (find(info.u) == find(info.v)) continue;
    merge(info.u, info.v);
    min_cost += info.cost;
  }
  cout << min_cost;
}