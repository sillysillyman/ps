#include <iostream>
#include <deque>

using namespace std;

int main() {
    int N, num;
    deque<pair<int, int>> dq;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> num;
        dq.push_back({i, num});
    }

    int idx = dq.front().first;
    int step = dq.front().second;

    dq.pop_front();
    cout << idx << ' ';
    while (!dq.empty()) {
        if (step > 0) {
            for (int i = 0; i < step - 1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            idx = dq.front().first;
            step = dq.front().second;
            dq.pop_front();
            cout << idx << ' ';
        } else if (step < 0) {
            for (int i = 0; i < -step - 1; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            idx = dq.back().first;
            step = dq.back().second;
            dq.pop_back();
            cout << idx << ' ';
        }
    }
}