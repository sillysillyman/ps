#include <iostream>

using namespace std;

int N;
int raw_graph[100][100];
int graph[100][100];
int visited[100][100];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

bool is_inside(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < N;
}

void dfs(int y, int x, int color, int area) {
    if (visited[y][x] || graph[y][x] != color || !is_inside(y, x)) return;
    visited[y][x] = 1;
    graph[y][x] = area;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        dfs(ny, nx, color, area);
    }
}

int main() {
    int area = 1;
    int area_cnt = 0;
    string line;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> line;
        for (int j = 0; j < N; j++) {
            raw_graph[i][j] = line[j];
            graph[i][j] = raw_graph[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]) continue;
            dfs(i, j, graph[i][j], area);
            area++;
            area_cnt = max(area_cnt, graph[i][j]);
        }
    }
    cout << area_cnt << ' ';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (raw_graph[i][j] == 'G') graph[i][j] = 'R';
            else graph[i][j] = raw_graph[i][j];
            visited[i][j] = 0;
        }
    }
    area = 1;
    area_cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]) continue;
            dfs(i, j, graph[i][j], area);
            area++;
            area_cnt = max(area_cnt, graph[i][j]);
        }
    }
    cout << area_cnt;
}