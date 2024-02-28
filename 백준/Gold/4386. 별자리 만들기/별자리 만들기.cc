#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Point {
  double x, y;
};

struct Edge {
  double dist;
  int p, q;
};

Point points[100];
int parents[100];
vector<Edge> edges;

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

double distance(Point p, Point q) {
  return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

int main() {
  int n;
  double min_dist = 0;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> points[i].x >> points[i].y;
    for (int j = 0; j < i; j++)
      edges.push_back({distance(points[i], points[j]), i, j});
  }
  for (int i = 0; i < n; i++) parents[i] = i;
  sort(edges.begin(), edges.end(),
       [](const Edge &a, const Edge &b) { return a.dist < b.dist; });
  for (auto edge : edges) {
    auto [dist, p, q] = edge;

    if (find(p) == find(q)) continue;
    min_dist += dist;
    merge(p, q);
  }
  cout << min_dist;
}