#include <iostream>

using namespace std;

int N, M;
int cnt = 0;
char campus[601][601];
int visited[601][601];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool is_inside(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < M;
}

void dfs(int y, int x) {
    if (!is_inside(y, x)) return;
    if (visited[y][x]) return;
    if (campus[y][x] == 'X') return;
    visited[y][x] = 1;
    if (campus[y][x] == 'P') cnt++;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        dfs(ny, nx);
    }
}

int main() {
    int x, y;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> campus[i][j];
            if (campus[i][j] == 'I') {
                y = i;
                x = j;
            }
        }
    }
    dfs(y, x);
    if (!cnt) cout << "TT";
    else cout << cnt;
}