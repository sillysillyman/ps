#include <iostream>

using namespace std;

typedef long long ll;

int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
    pair<int, int> v = {p2.first - p1.first, p2.second - p1.second};
    pair<int, int> w = {p3.first - p2.first, p3.second - p2.second};

    ll cross_product = (ll)v.first*w.second - (ll)w.first*v.second;

    if (cross_product < 0) return -1;
    else if (cross_product > 0) return 1;
    else return 0;
}

int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    bool cond1 = ccw({x1, y1}, {x2, y2}, {x3, y3})*ccw({x1, y1}, {x2, y2}, {x4, y4}) < 0;
    bool cond2 = ccw({x3, y3}, {x4, y4}, {x1, y1})*ccw({x3, y3}, {x4, y4}, {x2, y2}) < 0;
    
    if (cond1 && cond2) cout << 1;
    else cout << 0;
}