#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N, M;
    int x, y;
    int snakes_and_ladders[101] = {};
    int distance[101] = {};
    queue<int> q;

    cin >> N >> M;
    for (int i = 1; i < 101; i++) {
        snakes_and_ladders[i] = i;
        distance[i] = -1;
    }
    for (int i = 0; i < N + M; i++) {
        cin >> x >> y;
        snakes_and_ladders[x] = y;
    }
    distance[1] = 0;
    q.push(1);
    while (!q.empty()) {
        x = q.front();
        q.pop();
        for (int i = 1; i <= 6; i++) {
            y = x + i;
            if (y > 100) break;
            y = snakes_and_ladders[y];
            if (distance[y] == -1) {
                distance[y] = distance[x] + 1;
                q.push(y);
            }
        }
    }
    cout << distance[100];
}