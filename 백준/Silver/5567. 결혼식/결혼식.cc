#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int cnt = 0;
int visited[501];
vector<int> people[501];

void bfs() {
    queue<pair<int, int>> q;

    q.push({1, 0});
    visited[1] = 1;
    while (!q.empty()) {
        int person = q.front().first;
        int dist = q.front().second;

        q.pop();
        for (auto i : people[person]) {
            if (!visited[i]) {
                q.push({i, dist + 1});
                visited[i] = 1;
                if (dist + 1 <= 2) {
                    // cout << i << '\n';
                    cnt++;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to;

        cin >> from >> to;
        people[from].push_back(to);
        people[to].push_back(from);
    }
    bfs();
    // cout << "cnt = " << cnt;
    cout << cnt;
}