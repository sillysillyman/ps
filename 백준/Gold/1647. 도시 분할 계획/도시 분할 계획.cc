#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int from, to, cost;
};

int parents[100'001];
Edge edges[1'000'000];
vector<Edge> MST;

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

  int N, M;

  cin >> N >> M;
  for (int i = 1; i <= N; i++) parents[i] = i;
  for (int i = 0; i < M; i++)
    cin >> edges[i].from >> edges[i].to >> edges[i].cost;
  sort(edges, edges + M,
       [](const Edge& u, const Edge& v) { return u.cost < v.cost; });
  for (int i = 0; i < M; i++) {
    if (find(edges[i].from) == find(edges[i].to)) continue;
    merge(edges[i].from, edges[i].to);
    MST.push_back(edges[i]);
  }

  int sum = 0;

  for (int i = 0; i < MST.size() - 1; i++) sum += MST[i].cost;
  cout << sum;
}