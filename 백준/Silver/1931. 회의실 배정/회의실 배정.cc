#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    int N;
    int begin, end;
    int time;
    int cnt = 1;
    vector<pair<int, int>> schedule;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> begin >> end;
        schedule.push_back({begin, end});
    }
    sort(schedule.begin(), schedule.end(), cmp);
    time = schedule[0].second;
    for (int i = 1; i < N; i++) {
        if (schedule[i].first >= time) {
            time = schedule[i].second;
            cnt++;
        }
    }
    cout << cnt;
}