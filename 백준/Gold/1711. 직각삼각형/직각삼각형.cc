#include <iostream>
#include <map>

using namespace std;

struct Point {
  long long x, y;

  bool operator<(const Point& other) const {
    return x < other.x || (x == other.x && y < other.y);
  }
};

Point points[1500];

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

long long dot_product(Point p, Point q, Point r) {
  Point u = {p.x - q.x, p.y - q.y};
  Point v = {r.x - q.x, r.y - q.y};

  return u.x * v.x + u.y * v.y;
}

int main() {
  int N;
  int cnt = 0;

  cin >> N;
  for (int i = 0; i < N; i++) {
    int divisor;
    Point p;

    cin >> p.x >> p.y;
    points[i] = p;
  }
//   cout << '\n';
  for (int i = 0; i < N; i++) {
    map<Point, int> vectors;

    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      
      int divisor;
      Point vector = {points[j].x - points[i].x, points[j].y - points[i].y};

      divisor = gcd(abs(vector.x), abs(vector.y));
      if (divisor) {
        vector.x /= divisor;
        vector.y /= divisor;
      }
      vectors[vector]++;
    }
    // cout << "vectors:\n";
    // for (auto& vector : vectors) {
    //   cout << vector.first.x << ", " << vector.first.y  << ": " << vector.second << '\n';
    // }
    for (auto& vector : vectors) {
      if (Point orthogonal = {-vector.first.y, vector.first.x}; vectors.count(orthogonal)) {
        // cout << vector.first.x << ' ' << vector.first.y << '\n';
        // cout << -vector.first.y << ' ' << vector.first.x << '\n';
        cnt += vector.second * vectors[orthogonal];
      }
    }
    // cout << '\n';
  }
  cout << cnt;
}