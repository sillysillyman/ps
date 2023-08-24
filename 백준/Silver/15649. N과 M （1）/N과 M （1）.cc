#include <iostream>

using namespace std;

int N, M;
int nums[9];
int visited[9];

void dfs(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) cout << nums[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            nums[cnt] = i;
            dfs(cnt + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> N >> M;
    dfs(0);
}