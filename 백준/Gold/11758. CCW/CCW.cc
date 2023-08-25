#include <iostream>

using namespace std;

typedef pair<int, int> point;

int ccw(point p1, point p2, point p3) {
    point v = {p2.first - p1.first, p2.second - p1.second};
    point w = {p3.first - p2.first, p3.second - p2.second};

    int cross_product = v.first*w.second - w.first*v.second;

    if (cross_product < 0) return -1;
    else if (cross_product > 0) return 1;
    else return 0;
}

int main() {
    point P1, P2, P3;

    cin >> P1.first >> P1.second;
    cin >> P2.first >> P2.second;
    cin >> P3.first >> P3.second;
    cout << ccw(P1, P2, P3);
}