#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

deque<int> dq = {};
int op_cnt = 0;

bool is_near_to_left(int n) {
    int max_idx = dq.size() - 1;
    int idx = 0;
    for (auto i: dq) {
        if (i == n) break;
        else idx++;
    }
    if (idx <= max_idx/2) return true;
    else return false;
}

void shift_left() {
    int first = dq.front();
    dq.pop_front();
    dq.push_back(first);
    op_cnt++;
}

void shift_right() {
    int last = dq.back();
    dq.pop_back();
    dq.push_front(last);
    op_cnt++;
}

int main() {
    int N, M;
    vector<int> nums = {};

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }
    while (M--) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    reverse(nums.begin(), nums.end());
    while (!nums.empty()) {
        int n = nums.back();
        nums.pop_back();
        if (is_near_to_left(n)) {
            while (dq.front() != n) {
                shift_left();
            }
            dq.pop_front();
        } else {
            while (dq.front() != n) {
                shift_right();
            }
            dq.pop_front();
        }
    }
    cout << op_cnt;
}