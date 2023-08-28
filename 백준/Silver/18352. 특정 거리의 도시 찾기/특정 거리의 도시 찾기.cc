#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K, X;
int visited[300001] = {};
vector<int> cities;
vector<int> graph[300001];

void bfs(int x) {
    int dist = 0;
    queue<pair<int, int>> q;

    q.push({x, 0});
    visited[x] = 1;
    while (!q.empty()) {
        int city = q.front().first;
        int dist = q.front().second;

        q.pop();
        for (auto i : graph[city]) {
            if (!visited[i]) {
                q.push({i, dist + 1});
                visited[i] = 1;
                if (dist + 1 == K) cities.push_back(i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K >> X;
    for (int i = 0; i < M; i++) {
        int from, to;

        cin >> from >> to;
        graph[from].push_back(to);
    }
    bfs(X);
    sort(cities.begin(), cities.end());
    if (cities.empty()) cout << -1;
    else {
        for (auto city : cities) cout << city << '\n';
    }
}