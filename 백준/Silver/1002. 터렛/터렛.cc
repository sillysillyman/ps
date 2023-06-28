#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int T;
    int x1, y1, r1, x2, y2, r2;
    
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        float d = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));

        if (d == 0 && r1 == r2) {
            cout << -1 << endl;
        } else if (d > r1 + r2) {
            cout << 0 << endl;
        } else if (d < abs(r1 - r2)) {
            cout << 0 << endl;  
        } else if (d == r1 + r2) {
            cout << 1 << endl;
        } else if (d == abs(r1 - r2)) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }
}