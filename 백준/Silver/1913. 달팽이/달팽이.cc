#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    int x, y;

    cin >> N >> M;

    vector<vector<int>> graph(N, vector<int>(N));
    pair<int, int> pos = {N/2, N/2};
    int num = 1;
    int e = 2;

    while (!(pos.first == 0 && pos.second == 0)) {
        if (pos.first == N/2 && pos.second == N/2) {
            if (num == M) {
                x = pos.first + 1;
                y = pos.second + 1;
            }
            graph[pos.first][pos.second] = num;
            pos = make_pair(pos.first - 1, pos.second);
            num++;
        }
        for (int i = 0; i < e; i++) {
            if (num == M) {
                x = pos.first + 1;
                y = pos.second + 1;
            }
            graph[pos.first][pos.second] = num;
            if (i == e - 1) pos = make_pair(pos.first + 1, pos.second);
            else pos = make_pair(pos.first, pos.second + 1);
            num++;
        }
        for (int i = 0; i < e; i++) {
            if (num == M) {
                x = pos.first + 1;
                y = pos.second + 1;
            }
            graph[pos.first][pos.second] = num;
            if (i == e - 1) pos = make_pair(pos.first, pos.second - 1);
            else pos = make_pair(pos.first + 1, pos.second);
            num++;
        }
        for (int i = 0; i < e; i++) {
            if (num == M) {
                x = pos.first + 1;
                y = pos.second + 1;
            }
            graph[pos.first][pos.second] = num;
            if (i == e - 1) pos = make_pair(pos.first - 1, pos.second);
            else pos = make_pair(pos.first, pos.second - 1);
            num++;
        }
        for (int i = 0; i < e; i++) {
            if (num == M) {
                x = pos.first + 1;
                y = pos.second + 1;
            }
            graph[pos.first][pos.second] = num;
            if (pos.first == 0 && pos.second == 0) break;
            pos = make_pair(pos.first - 1, pos.second);
            num++;
        }
        e += 2;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << x << ' ' << y;
}