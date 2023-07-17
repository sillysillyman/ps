#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    int num;
    deque<int> difficulties;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        difficulties.push_back(num);
    }
    sort(difficulties.begin(), difficulties.end());

    int trim_cnt = round(n*0.15);
    
    for (int i = 0; i < trim_cnt; i++) {
        if (difficulties.size() <= 2) {
            cout << 0;
            return 0;
        }
        difficulties.pop_front();
        difficulties.pop_back();
    }

    int sum = 0;

    for (auto difficulty : difficulties) sum += difficulty;
    if (difficulties.size() == 0) cout << 0;
    else cout << round((float)sum/difficulties.size());
}