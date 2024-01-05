#include <iostream>
#include <map>

using namespace std;

struct Point {
  int x, y;

  bool operator<(const Point& other) const {
    return x < other.x || (x == other.x && y < other.y);
  }
};

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

map<Point, int> points;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  Point point;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> point.x >> point.y;

    int divisor = gcd(abs(point.x), abs(point.y));

    if (divisor) point.x /= divisor, point.y /= divisor;
    points[point]++;
  }

  int max_score = 0;

  for (auto& point : points) max_score = max(max_score, point.second);
  cout << max_score;
}