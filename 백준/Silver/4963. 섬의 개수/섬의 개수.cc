#include <iostream>

using namespace std;

int w, h;
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int graph[50][50];
int visited[50][50];

void reset() {
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            graph[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

bool is_inside(int y, int x) {
    return 0 <= y && y < h && 0 <= x && x < w;
}

void dfs(int y, int x, int mark) {
    if (!graph[y][x] || visited[y][x]) return;
    visited[y][x] = mark;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (is_inside(ny, nx)) dfs(ny, nx, mark);
        }
    }
}

int main() {
    int mark;
    
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        reset();
        mark = 1;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) cin >> graph[i][j];
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (graph[i][j] && !visited[i][j]) {
                    dfs(i, j, mark);
                    mark++;
                }
            }
        }
        cout << mark - 1 << '\n';
    }
}