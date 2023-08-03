#include <iostream>

using namespace std;

int main() {
    int a1, a0;
    int c;
    int n0;
    bool success = true;

    cin >> a1 >> a0 >> c >> n0;
    if (c < a1) cout << 0;
    else {
        for (int i = n0; i <= 100; i++) {
            if (a1*n0 + a0 > c*n0) {
                success = false;
                break;
            }
        }
        if (success) cout << 1;
        else cout << 0;
    }
}