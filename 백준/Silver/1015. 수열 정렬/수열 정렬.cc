#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    int x;
    vector<pair<int, int>> v;
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x;
        v.push_back(make_pair(x, i));
    }
    sort(v.begin(), v.end());

    vector<int> p(N);

    for (int i = 0; i < N; i++) {
        p[v[i].second] = i;
    }
    for (auto i: p) {
        cout << i << " ";
    }
}