#include <iostream>

using namespace std;

int main() {
    int A, B, C, D;
    int h, m, s;

    cin >> A >> B >> C >> D;
    s = C + D%60;
    m = B + (D/60)%60;
    h = A + (D/3600)%24;
    if (s >= 60) {
        s %= 60;
        m += 1;
    }
    if (m >= 60) {
        m %= 60;
        h += 1;
    }
    if (h >= 24) h %= 24;
    cout << h << " " << m << " " << s;
}