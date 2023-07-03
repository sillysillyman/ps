#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_NODE = 1001;
vector<int> graph[MAX_NODE] = {};
int visited[MAX_NODE] = {};

void dfs(int node) {
    visited[node] = 1;
    cout << node << ' ';
    for (auto v : graph[node]) {
        if (!visited[v]) dfs(v);
    }
}

void bfs(int node) {
    queue<int> q;
    int curr;
    
    q.push(node);
    visited[node] = 1;
    while (!q.empty()) {
        curr = q.front();
        cout << curr << ' ';
        q.pop();
        for (int next : graph[curr]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = 1;
            }
        }
    }
}

int main() {
    int N, M, V;
    int v1, v2;

    cin >> N >> M >> V;
    while (M--) {
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for (int i = 0; i < MAX_NODE; i++) {
        if (graph[i].empty()) continue;
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(V);
    cout << endl;
    for (int i = 0; i < MAX_NODE; i++) visited[i] = 0;
    bfs(V);
}