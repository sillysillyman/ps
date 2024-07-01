#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

struct Point {
  long long x, y;
};

int main() {
  int T;

  scanf("%d", &T);
  while (T--) {
    int N;
    double min_sum = 2'000'000 * sqrt(2);
    vector<bool> flags;
    vector<Point> points;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      int x, y;

      scanf("%d %d", &x, &y);
      points.push_back(Point{x, y});
    }
    flags.assign(N, true);
    for (int i = 0; i < N / 2; i++) flags[i] = false;
    do {
      Point v = {0, 0};
      vector<Point> starts, ends;

      for (int i = 0; i < N; i++) {
        if (flags[i])
          starts.push_back(points[i]);
        else
          ends.push_back(points[i]);
      }
      for (int i = 0; i < N / 2; i++) {
        v.x += ends[i].x - starts[i].x;
        v.y += ends[i].y - starts[i].y;
      }
      min_sum = min(min_sum, sqrt(v.x * v.x + v.y * v.y));
    } while (next_permutation(flags.begin(), flags.end()));
    printf("%.6lf\n", min_sum);
  }
}