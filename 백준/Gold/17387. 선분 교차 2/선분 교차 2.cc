#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<int, int> point;
typedef pair<point, point> line;

int ccw(point p1, point p2, point p3) {
    point v = {p2.first - p1.first, p2.second - p1.second};
    point w = {p3.first - p2.first, p3.second - p2.second};
    ll cross_product = (ll)v.first*w.second - (ll)w.first*v.second;

    if (cross_product < 0) return -1;
    else if (cross_product > 0) return 1;
    else return 0;
}

bool is_on_the_line(point p, line l) {
    if (ccw(l.first, l.second, p) != 0) return false;
    
    int x = p.first, y = p.second;
    int x1 = l.first.first, y1 = l.first.second;
    int x2 = l.second.first, y2 = l.second.second;

    if (x1 <= x && x <= x2 && y1 <= y && y <= y2) return true;
    else if (x2 <= x && x <= x1 && y1 <= y && y <= y2) return true;
    else if (x1 <= x && x <= x2 && y2 <= y && y <= y1) return true;
    else if (x2 <= x && x <= x1 && y2 <= y && y <= y1) return true;
    else return false;
}

int main() {
    line L1, L2;
    point P1, P2, P3, P4;

    cin >> P1.first >> P1.second >> P2.first >> P2.second;
    cin >> P3.first >> P3.second >> P4.first >> P4.second;
    L1 = {P1, P2};
    L2 = {P3, P4};

    if ((ccw(P1, P2, P3)*ccw(P1, P2, P4) < 0) && (ccw(P3, P4, P1)*ccw(P3, P4, P2) < 0)) cout << 1;
    else {
        if (is_on_the_line(P1, L2) || is_on_the_line(P2, L2) || is_on_the_line(P3, L1) || is_on_the_line(P4, L1)) cout << 1;
        else cout << 0;
    }
}