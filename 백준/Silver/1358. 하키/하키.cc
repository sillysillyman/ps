#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int W, H, X, Y, P, R;
    int x, y;
    int cnt = 0;

    cin >> W >> H >> X >> Y >> P;
    R = H/2;
    while (P--) {
        cin >> x >> y;
        if ((X <= x && x <= X + W) && (Y <= y && y <= Y + H)) cnt++;
        else if (sqrt((X - x)*(X - x) + (Y + R - y)*(Y + R - y)) <= R) cnt++;
        else if (sqrt((X + W - x)*(X + W - x) + (Y + R - y)*(Y + R - y)) <= R) cnt++;
        else continue;
    }
    cout << cnt;
}