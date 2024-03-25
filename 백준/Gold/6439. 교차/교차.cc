#include <iostream>

using namespace std;

struct Point;
int ccw(Point p, Point q, Point r);

struct Point {
  int x, y;
};

struct Line {
  Point start, end;

  bool does_intersect(Line line) {
    if (!ccw(start, end, line.start) && !ccw(start, end, line.end))
      return (start.x <= line.start.x && line.start.x <= end.x &&
              start.y <= line.start.y && line.start.y <= end.y) ||
             (start.x <= line.end.x && line.end.x <= end.x &&
              start.y <= line.end.y && line.end.y <= end.y);
    else if (!ccw(start, end, line.start))
      return start.x <= line.start.x && line.start.x <= end.x &&
             start.y <= line.start.y && line.start.y <= end.y;
    else if (!ccw(start, end, line.end))
      return start.x <= line.end.x && line.end.x <= end.x &&
             start.y <= line.end.y && line.end.y <= end.y;
    return ccw(start, end, line.start) * ccw(start, end, line.end) < 0 &&
           ccw(line.start, line.end, start) * ccw(line.start, line.end, end) <
               0;
  }
};

struct Rectangle {
  Line left, bottom, top, right;

  bool does_include(Line line) {
    return (left.start.x <= line.start.x && line.start.x <= right.end.x &&
            left.start.y <= line.start.y && line.start.y <= right.end.y) &&
           (left.start.x <= line.end.x && line.end.x <= right.end.x &&
            left.start.y <= line.end.y && line.end.y <= right.end.y);
  }
};

int ccw(Point p, Point q, Point r) {
  if (int cross_product = (q.x - p.x) * (r.y - p.y) - (r.x - p.x) * (q.y - p.y);
      cross_product)
    return cross_product / abs(cross_product);
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;

  cin >> T;
  while (T--) {
    Point p, q;
    Line l;
    Rectangle r;

    cin >> l.start.x >> l.start.y >> l.end.x >> l.end.y;
    cin >> p.x >> p.y >> q.x >> q.y;
    if (l.start.x > l.end.x || (l.start.x == l.end.x && l.start.y > l.end.y))
      swap(l.start, l.end);
    if (p.x > q.x) swap(p, q);
    if (p.y > q.y) swap(p.y, q.y);
    r.left = {p, {p.x, q.y}};
    r.bottom = {p, {q.x, p.y}};
    r.top = {{p.x, q.y}, q};
    r.right = {{q.x, p.y}, q};
    if (r.does_include(l) || l.does_intersect(r.left) ||
        l.does_intersect(r.bottom) || l.does_intersect(r.top) ||
        l.does_intersect(r.right))
      cout << "T\n";
    else
      cout << "F\n";
  }
}