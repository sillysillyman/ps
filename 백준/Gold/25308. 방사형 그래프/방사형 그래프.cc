#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

struct Point {
  double x, y;
};

int idxs[8] = {0, 1, 2, 3, 4, 5, 6, 7};
double arr[8];
Point points[8];

int ccw(Point p, Point q, Point r) {
  if (double cross_product =
          (q.x - p.x) * (r.y - p.y) - (r.x - p.x) * (q.y - p.y);
      cross_product)
    return cross_product / abs(cross_product);
  return 0;
}

int main() {
  int cnt = 0;

  for (int i = 0; i < 8; i++) cin >> arr[i];
  do {
    bool is_radar = true;

    points[0] = {0, arr[idxs[0]]};
    points[1] = {arr[idxs[1]] / sqrt(2), arr[idxs[1]] / sqrt(2)};
    points[2] = {arr[idxs[2]], 0};
    points[3] = {arr[idxs[3]] / sqrt(2), -arr[idxs[3]] / sqrt(2)};
    points[4] = {0, -arr[idxs[4]]};
    points[5] = {-arr[idxs[5]] / sqrt(2), -arr[idxs[5]] / sqrt(2)};
    points[6] = {-arr[idxs[6]], 0};
    points[7] = {-arr[idxs[7]] / sqrt(2), arr[idxs[7]] / sqrt(2)};
    for (int i = 0; i < 6; i++)
      is_radar &= ccw(points[i], points[i + 1], points[i + 2]) < 0;
    is_radar &= ccw(points[6], points[7], points[0]) < 0;
    is_radar &= ccw(points[7], points[0], points[1]) < 0;
    if (is_radar) cnt++;
  } while (next_permutation(idxs, idxs + 8));
  cout << cnt;
}