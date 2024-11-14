#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

struct Point {
  int x, y, idx;
};

struct Edge {
  double dist;
  Point u, v;

  Edge(Point u, Point v) {
    dist = hypot(u.x - v.x, u.y - v.y);
    this->u = u;
    this->v = v;
  }

  bool operator<(const Edge& other) const { return dist < other.dist; }
};

vector<int> p;

int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

void unite(int x, int y) { p[find(x)] = find(y); }

int main() {
  int n;
  int t = 0;

  while (scanf("%d", &n) && n) {
    int x, y;
    vector<Point> points(n);
    vector<Edge> edges;

    p.resize(n);
    for (int i = 0; i < n; i++) p[i] = i;

    for (int i = 0; i < n; i++) {
      scanf("%d%d", &x, &y);
      points[i] = {x, y, i};
    }

    for (int i = 0, size = points.size(); i < size - 1; i++)
      for (int j = i + 1; j < size; j++)
        edges.push_back(Edge(points[i], points[j]));

    double max_dist = 0;
    sort(edges.begin(), edges.end());
    for (auto [dist, u, v] : edges) {
      if (find(u.idx) == find(v.idx)) continue;
      unite(u.idx, v.idx);
      max_dist = max(max_dist, dist);
      if (find(0) == find(1)) break;
    }

    printf("Scenario #%d\nFrog Distance = %.3lf\n\n", ++t, max_dist);
  }
}