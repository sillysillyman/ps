#include <cstdio>
#include <numeric>
#include <vector>

using namespace std;

struct Edge {
  int u, v, w;
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
  for (int i = 0; i < M; i++) {
    int u, v;

    scanf("%d%d", &u, &v);
    --u, --v;
    edges[M - i - 1] = {u, v, i + 1};
  }

  while (K) {
    int score = 0;

    iota(p.begin(), p.end(), 0);
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