#include <iostream>

using namespace std;

int main() {
    int h, m, s;
    int time[6];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) cin >> time[j];
        s = time[5] - time[2];
        if (s < 0) {
            s += 60;
            time[4]--;
        }
        m = time[4] - time[1];
        if (m < 0) {
            m += 60;
            time[3]--;
        }
        h = time[3] - time[0];
        cout << h << ' ' << m << ' ' << s << '\n';
    }
}