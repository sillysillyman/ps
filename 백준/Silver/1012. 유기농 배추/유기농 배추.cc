#include <iostream>
#include <memory.h>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int field[50][50] = {};
int visited[50][50] = {};

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if (new_x < 0 || new_y < 0 || new_x >= 50 || new_y >= 50) continue;
        if (field[new_x][new_y] == 1 && !visited[new_x][new_y]) {
            visited[new_x][new_y]++;
            dfs(new_x, new_y);
        }
    }
}

int main() {
    int T;
    int M, N, K;
    int X, Y;

    cin >> T;

    while (T--) {
        int cnt = 0;

        cin >> M >> N >> K;

        memset(field, 0, sizeof(field));
        memset(visited, 0, sizeof(visited));

        while (K--) {
            cin >> X >> Y;
            field[X][Y] = 1;
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (field[i][j] == 1 && !visited[i][j]) {
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cout << cnt << endl;
    }
}