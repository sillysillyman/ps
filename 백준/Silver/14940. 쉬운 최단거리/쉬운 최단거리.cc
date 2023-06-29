#include <iostream>
#include <queue>

using namespace std;

int n, m;
int graph[1000][1000];
int distances[1000][1000];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

bool is_inside(int x, int y) {
    return x >= 0 && x < 1000 && y >= 0 && y < 1000;
}

void bfs() {
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        
        q.pop();
        distances[y][x]++;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (is_inside(nx, ny) && graph[ny][nx] != 0) {
                if (distances[ny][nx] == -1) {
                    distances[ny][nx] = distances[y][x];
                    q.push({ny, nx});
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0) distances[i][j] = 0;
            else distances[i][j] = -1;
            if (graph[i][j] == 2) q.push({i, j});
        }
    }
    bfs();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << distances[i][j] << " ";
        }
        cout << endl;
    }
}