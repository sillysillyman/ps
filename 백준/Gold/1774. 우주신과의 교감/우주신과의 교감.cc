#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
  int idx;
  long long x, y;
};

struct Edge {
  double dist;
  Point p, q;
};

int parents[1000];
vector<Point> points;
vector<Edge> edges;

double distance(Point& p, Point& q) {
  return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

int find(int p) {
  if (p == parents[p]) return p;
  return parents[p] = find(parents[p]);
}

void merge(int p, int q) {
  p = find(p);
  q = find(q);
  if (p == q) return;
  if (p < q)
    parents[q] = p;
  else
    parents[p] = q;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  double min_dist = 0;

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    long long X, Y;
    
    cin >> X >> Y;
    points.push_back({i, X, Y});
  }
  for (int i = 1; i <= N; i++) parents[i] = i;
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++)
      edges.push_back({distance(points[i], points[j]), points[i], points[j]});
  }
  for (int p, q, i = 0; i < M; i++) {
    cin >> p >> q;
    merge(find(p), find(q));
  }
  sort(edges.begin(), edges.end(),
       [](Edge& u, Edge& v) { return u.dist < v.dist; });
  for (auto edge : edges) {
    if (find(edge.p.idx) == find(edge.q.idx)) continue;
    merge(edge.p.idx, edge.q.idx);
    min_dist += edge.dist;
  }
  cout << fixed;
  cout.precision(2);
  cout << min_dist;
}