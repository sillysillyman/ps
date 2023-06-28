#include <iostream>
#include <math.h>

using namespace std;

bool is_inside_circle(int x, int y, int cx, int cy, int r) {
    float d = sqrt(pow(x - cx, 2) + pow(y - cy, 2));
    if (d < r) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int T;
    int x1, y1, x2, y2;
    int n;
    int cx, cy, r;
        
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> n;
        int cnt1 = 0;
        int cnt2 = 0;
        for (int j = 0; j < n; j++) {
            cin >> cx >> cy >> r;
            if (is_inside_circle(x1, y1, cx, cy, r) && is_inside_circle(x2, y2, cx, cy, r)) {
                continue;
            } else if (is_inside_circle(x1, y1, cx, cy, r)) {
                cnt1++;
            } else if (is_inside_circle(x2, y2, cx, cy, r)) {
                cnt2++;
            } else {
                continue;
            }
        }
        cout << cnt1 + cnt2 << endl;
    }
}