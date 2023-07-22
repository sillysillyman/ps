#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    int N, M;
    int idx, priority;
    int cnt;
    
    cin >> T;
    while (T--) {
        queue<pair<int, int>> q;
        queue<int> p;
        vector<int> v;
        
        cnt = 0;
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            cin >> priority;
            q.push({i, priority});
            v.push_back(priority);
        }
        sort(v.begin(), v.end(), greater<>());
        for (int num : v) p.push(num);
        while (1) {
            pair<int, int> front = q.front();
            if (front.second == p.front()) {
                q.pop();
                p.pop();
                cnt++;
                if (front.first == M) break;
            } else {
                q.pop();
                q.push(front);
            }
        }
        cout << cnt << '\n';
    }
}