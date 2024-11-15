#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

struct Edge {
  int u, v, w;

  bool operator>(const Edge& other) const { return w > other.w; }
};

vector<int> p;
vector<Edge> edges;

int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

void unite(int x, int y) { p[find(x)] = find(y); }

int main() {
  int N, M, K;

  scanf("%d%d%d", &N, &M, &K);
  p.resize(N);
  edges.resize(M);
  for (int i = 0; i < N; i++) p[i] = i;
  for (int i = 0; i < M; i++) {
    int u, v;

    scanf("%d%d", &u, &v);
    --u, --v;
    edges[i] = {u, v, i + 1};
  }

  sort(edges.begin(), edges.end(), greater());
  while (K) {
    int score = 0;

    for (int i = 0; i < N; i++) p[i] = i;
    for (int i = M - 1; i >= 0; i--) {
      auto [u, v, w] = edges[i];

      if (find(u) == find(v)) continue;
      unite(u, v);
      score += w;
    }

    bool flag = false;
    int root = find(0);
    for (int i = 1; i < N; i++) {
      if (find(i) != root) {
        flag = true;
        break;
      }
    }
    if (flag) break;

    printf("%d ", score);
    --M;
    --K;
  }
  while (K--) printf("0 ");
}