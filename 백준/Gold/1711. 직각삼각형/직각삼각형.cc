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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  int cnt = 0;

  cin >> N;
  for (int i = 0; i < N; i++) {
    int divisor;
    Point point;

    cin >> point.x >> point.y;
    points[i] = point;
  }
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
    for (auto& vector : vectors) {
      if (Point orthogonal = {-vector.first.y, vector.first.x};
          vectors.count(orthogonal))
        cnt += vector.second * vectors[orthogonal];
    }
  }
  cout << cnt;
}