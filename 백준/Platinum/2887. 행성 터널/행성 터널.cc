#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct Point {
  int idx, x, y, z;
};

struct Edge {
  Point from, to;
  ll cost;
};

int parents[100'000];
Point points[100'000];
vector<Edge> edges;

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
  int N;

  cin >> N;
  for (int i = 0; i < N; i++) {
    points[i].idx = i;
    parents[points[i].idx] = i;
    cin >> points[i].x >> points[i].y >> points[i].z;
  }
  sort(points, points + N,
       [](const Point& p, const Point& q) { return p.x < q.x; });
  for (int i = 0; i < N - 1; i++) {
    Edge edge;

    edge.from = points[i];
    edge.to = points[i + 1];
    edge.cost = (ll)points[i + 1].x - (ll)points[i].x;
    edges.push_back(edge);
  }
  sort(points, points + N,
       [](const Point& p, const Point& q) { return p.y < q.y; });
  for (int i = 0; i < N - 1; i++) {
    Edge edge;

    edge.from = points[i];
    edge.to = points[i + 1];
    edge.cost = (ll)points[i + 1].y - (ll)points[i].y;
    edges.push_back(edge);
  }
  sort(points, points + N,
       [](const Point& p, const Point& q) { return p.z < q.z; });
  for (int i = 0; i < N - 1; i++) {
    Edge edge;

    edge.from = points[i];
    edge.to = points[i + 1];
    edge.cost = (ll)points[i + 1].z - (ll)points[i].z;
    edges.push_back(edge);
  }
  sort(edges.begin(), edges.end(),
       [](const Edge& u, const Edge& v) { return u.cost < v.cost; });

  ll cost = 0;

  for (auto& edge : edges) {
    if (find(edge.from.idx) == find(edge.to.idx)) continue;
    merge(edge.from.idx, edge.to.idx);
    cost += edge.cost;
  }
  cout << cost;
}