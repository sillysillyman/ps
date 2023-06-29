#include <iostream>
#include <queue>

using namespace std;

int position[100001];
queue<int> q;

void bfs(int dst) {
    while (!q.empty()) {
        int x = q.front();

        q.pop();
        if (x >= 1 && position[x - 1] > position[x] + 1) {
            position[x - 1] = position[x] + 1;
            q.push(x - 1);
        }
        if (x <= 99999 && position[x + 1] > position[x] + 1) {
            position[x + 1] = position[x] + 1;
            q.push(x + 1);
        }
        if (x <= 50000 && position[2*x] > position[x] + 1) {
            position[2*x] = position[x] + 1;
            q.push(2*x);
        }
        if (x == dst) break;
        // cout << endl;
        // for (int i = 0; i < 50; i++) {
        // cout << position[i] << " ";
        // }
        // cout << endl;
    }
}

int main() {
    int N, K;

    cin >> N >> K;
    q.push(N);
    for (int i = 0; i <= 100000; i++) {
        position[i] = 100000;
    }
    position[N] = 0;
    bfs(K);
    // for (int i = 0; i < 50; i++) {
    //     cout << position[i] << " ";
    // }
    // cout << endl;
    cout << position[K];
}