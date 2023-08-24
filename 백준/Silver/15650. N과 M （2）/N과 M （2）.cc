#include <iostream>

using namespace std;

int N, M;
int nums[9] = {};
int visited[9] = {};

void dfs(int num, int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) cout << nums[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = num; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            nums[cnt] = i;
            dfs(i + 1, cnt + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> N >> M;
    dfs(1, 0);
}