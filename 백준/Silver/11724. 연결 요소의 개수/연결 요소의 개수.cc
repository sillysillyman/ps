#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> graph[1001];
int visited[1001];

void dfs(int node) {
    if (visited[node]) return;
    else {
        visited[node] = 1;
        for (auto i: graph[node]) {
            dfs(i);
        }
    }
}

int main() {
    int u, v;
    int components;
    
    cin >> N >> M;
    components = N;
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 0; i <= N; i++) {
        if (visited[i]) components--;
        if (graph[i].empty()) continue;
        dfs(i);
    }
    cout << components;
}