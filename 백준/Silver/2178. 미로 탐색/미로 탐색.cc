#include <iostream>
#include <queue>

using namespace std;

int maze[100][100];
int visited[100][100];
int dist[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int start_x, int start_y, int end_x, int end_y) {
    queue<pair<int, int>> q;
    pair<int, int> curr;

    q.push({start_x, start_y});
    visited[start_x][start_y] = 1;
    dist[start_x][start_y]++;
    while(!q.empty()) {
        curr = q.front();
        q.pop();

        int curr_x = curr.first;
        int curr_y = curr.second;

        for (int i = 0; i < 4; i++) {
            int next_x = curr_x + dx[i];
            int next_y = curr_y + dy[i];

            if ((start_x <= next_x && next_x < end_x) && (start_y <= next_y && next_y < end_y)) {
                if (maze[next_x][next_y] && !visited[next_x][next_y]) {
                    q.push({next_x, next_y});
                    visited[next_x][next_y] = 1;
                    dist[next_x][next_y] = dist[curr_x][curr_y] + 1;
                }
            }
        }
    }
}

int main() {
    int N, M;
    string line;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> line;
        for (int j = 0; j < M; j++) {
            maze[i][j] = line[j] - '0';
        }
    }
    bfs(0, 0, N, M);
    cout << dist[N - 1][M - 1];
}