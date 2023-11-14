#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int cnt;
int graph[100][100];
int visited[100][100];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void reset_visited() {
    fill(&visited[0][0], &visited[N - 1][N], 0);
}

bool is_inside(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool is_safe(int x, int y, int rain) {
    return graph[x][y] > rain;
}

void bfs(int x, int y, int rain) {
    if (visited[x][y] || !is_inside(x, y) || !is_safe(x, y, rain)) return;

    queue<pair<int, int>> q;
    
    q.push({x, y});
    visited[x][y] = cnt;
    while (!q.empty()) {
        pair<int, int> front = q.front();

        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = front.first + dx[i];
            int ny = front.second + dy[i];

            if (visited[nx][ny] || !is_inside(nx, ny) || !is_safe(nx, ny, rain)) continue;
            visited[nx][ny] = cnt;
            q.push({nx, ny});
        }
    }
}

int main() {
    int max_rain = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
            max_rain = max(max_rain, graph[i][j]);
        }
    }
    // cout << '\n';
    int safe_areas = 0;

    for (int rain = 0; rain <= max_rain; rain++) {
        reset_visited();
        // cout << "rain: " << rain << '\n';
        cnt = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j] || !is_safe(i, j, rain)) continue;
                bfs(i, j, rain);
                cnt++;
            }
        }
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < N; j++) {
        //         cout << visited[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';

        for (int i = 0; i < N; i++) safe_areas = max(safe_areas, *max_element(visited[i], visited[i] + N));
    }
    cout << safe_areas;
}