#include <iostream>

using namespace std;

int main() {
    int x, y, w, h;
    int x_dist, y_dist;

    cin >> x >> y >> w >> h;
    x_dist = (x > w - x) ? (w - x) : x;
    y_dist = (y > h - y) ? (h - y) : y;
    cout << ((x_dist > y_dist) ? y_dist : x_dist);
}