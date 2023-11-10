#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int score[10];
    int accumulated[10];

    for (int i = 0; i < 10; i++) cin >> score[i];
    for (int i = 0; i < 10; i++) {
        if (i == 0) accumulated[i] = score[i];
        else accumulated[i] = accumulated[i - 1] + score[i];
    }

    int diff = abs(accumulated[0] - 100);
    int res = accumulated[0];

    for (int i = 1; i < 10; i++) {
        if (diff < abs(accumulated[i] - 100)) break;
        else if (diff >= abs(accumulated[i] - 100)) {
            diff = abs(accumulated[i] - 100);
            res = accumulated[i];
        }
    }
    cout << res;
}