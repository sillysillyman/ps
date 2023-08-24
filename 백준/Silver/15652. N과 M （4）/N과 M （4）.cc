#include <iostream>

using namespace std;

int N, M;
int nums[9];

void dfs(int num, int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) cout << nums[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = num; i <= N; i++) {
        nums[cnt] = i;
        dfs(i, cnt + 1);
    }
}

int main() {
    cin >> N >> M;
    dfs(1, 0);
}