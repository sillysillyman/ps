#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool is_clock_number(int n) {
    if (n > 9999) return false;

    int clock_number = n;
    queue<int> q;

    for (int i = 1000; i >= 1; i /= 10) {
        q.push(n/i);
        n %= i;
    }

    int top = q.front();

    q.pop();
    q.push(top);

    for (int i = 0; i < 3; i++) {
        int num = 0;
        int top;

        for (int j = 1000; j >= 1; j /= 10) {
            top = q.front();
            num += j*top;
            q.pop();
            q.push(top);
        }
        if (num < clock_number) return false;
        top = q.front();
        q.pop();
        q.push(top);
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int clock_number = 9999;
    queue<int> cross_card;
    vector<int> clock_numbers;

    for (int i = 0; i < 4; i++) {
        int num;

        cin >> num;
        cross_card.push(num);
    }
    for (int i = 0; i < 4; i++) {
        int num = 0;
        int top;

        for (int j = 1000; j >= 1; j /= 10) {
            top = cross_card.front();
            num += j*top;
            cross_card.pop();
            cross_card.push(top);
        }
        clock_number = min(num, clock_number);
        top = cross_card.front();
        cross_card.pop();
        cross_card.push(top);
    }
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            for (int k = 1; k <= 9; k++) {
                for (int l = 1; l <= 9; l++) {
                    int num = 1000*i + 100*j + 10*k + l;

                    if (is_clock_number(num)) {
                        clock_numbers.push_back(num);
                        if (num == clock_number) {
                            cout << clock_numbers.size();
                            break;
                        }
                    }
                }
            }
        }
    }
}