#include <iostream>
#include <queue>

using namespace std;

int H, W;
int sheep_cnt;
int grid[100][100];
int visited[100][100];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool is_inside(int x, int y) {
    return x >= 0 && x < H && y >= 0 && y < W;
}

void bfs(int x, int y) {
    if (visited[x][y] || !grid[x][y]) return;
    
    queue<pair<int, int>> q;
    
    visited[x][y] = sheep_cnt;
    q.push({x, y});
    while (!q.empty()) {
        pair<int, int> front = q.front();

        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = front.first + dx[i];
            int ny = front.second + dy[i];

            if (!is_inside(nx, ny) || visited[nx][ny]) continue;
            if (grid[nx][ny] == 1) {
                visited[nx][ny] = sheep_cnt;
                q.push({nx, ny});
            }
        }
    }
    sheep_cnt++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    cin >> T;
    while (T--) {
        sheep_cnt = 0;
        fill(&grid[0][0], &grid[99][100], 0);
        fill(&visited[0][0], &visited[99][100], 0);
        cin >> H >> W;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                char c;

                cin >> c;
                if (c == '.') grid[i][j] = 0;
                else if (c == '#') {
                    grid[i][j] = 1;
                    sheep_cnt = 1;
                }
            }
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) bfs(i, j);
        }
        if (sheep_cnt == 0) cout << sheep_cnt << '\n';
        else cout << sheep_cnt - 1 << '\n';
    }
}