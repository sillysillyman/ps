#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

struct Edge {
  int from, to, len;

  bool operator<(const Edge& other) const { return len < other.len; }
};

int total_len, mst_len;
vector<Edge> edges;

int p[50];

int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

void unite(int x, int y) { p[find(x)] = find(y); }

int main() {
  int N;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) p[i] = i;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      char ch;
      int len;
      scanf(" %c", &ch);
      len = ch == '0' ? 0 : ch >= 'a' ? ch - 'a' + 1 : ch - 'A' + 27;
      total_len += len;
      if (i != j && ch != '0') edges.push_back({i, j, len});
    }
  }

  sort(edges.begin(), edges.end());
  for (auto& edge : edges) {
    if (find(edge.from) != find(edge.to)) {
      unite(edge.from, edge.to);
      mst_len += edge.len;
    }
  }

  bool is_connected = true;
  int root = find(0);
  for (int i = 0; i < N; i++) {
    if (find(i) != root) {
      is_connected = false;
      break;
    }
  }

  printf("%d", is_connected ? total_len - mst_len : -1);
}