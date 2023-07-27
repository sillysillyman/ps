#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<int, int> order;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return order[a.first] < order[b.first];
    return a.second > b.second;
}

int main() {
    int N, C;
    map<int, int> m;

    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        int num;

        cin >> num;
        m[num]++;
        if (!order[num]) order[num] = i + 1;
    }

    vector<pair<int, int>> v(m.begin(), m.end());

    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].second; j++) cout << v[i].first << ' ';
    }
}