#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int complex_size;
int graph[25][25];
int visited[25][25];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
vector<int> complex_sizes;

bool is_inside(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < N;
}

void dfs(int y, int x) {
    if (visited[y][x]) return;
    if (!is_inside(y, x) || graph[y][x] == 0) return;
    visited[y][x] = 1;
    complex_size++;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        dfs(ny, nx);
    }
}

int main() {
    int cnt = 0;
    string line;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> line;
        for (int j = 0; j < N; j++) {
            graph[i][j] = line[j] - '0';
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && graph[i][j]) cnt++;
            if (!graph[i][j] || visited[i][j]) continue;
            complex_size = 0;
            dfs(i, j);
            complex_sizes.push_back(complex_size);
        }
    }
    sort(complex_sizes.begin(), complex_sizes.end());
    cout << cnt << endl;
    for (auto complex_size : complex_sizes) cout << complex_size << endl;
}