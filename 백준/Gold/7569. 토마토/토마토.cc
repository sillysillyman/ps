#include <iostream>
#include <queue>

using namespace std;

int M, N, H;
int box[100][100][100];
int visited[100][100][100];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
struct tomato {
    int x, y, z;
};
queue<tomato> tomatoes;

bool is_inside(int x, int y, int z) {
    return x >= 0 && x < M && y >= 0 && y < N && z >= 0 && z < H;
}

void bfs(int x, int y, int z) {
    while (!tomatoes.empty()) {
        tomato t = tomatoes.front();

        tomatoes.pop();
        visited[t.z][t.y][t.x] = 1;
        for (int i = 0; i < 6; i++) {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            int nz = t.z + dz[i];

            if (is_inside(nx, ny, nz) &&!visited[nz][ny][nx] && box[nz][ny][nx] == 0) {
                box[nz][ny][nx] = box[t.z][t.y][t.x] + 1;
                tomatoes.push({nx, ny, nz});
            }
        }
    }
}

int main() {
    cin >> M >> N >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1) tomatoes.push({k, j, i});
            }
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (box[i][j][k] <= 0) continue;
                if (!visited[i][j][k]) bfs(i, j, k);
            }
        }
    }

    int day = 1 << 31;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (box[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                } else day = max(day, box[i][j][k]);
            }
        }
    }
    cout << day - 1;
}