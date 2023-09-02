#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[9];
int nums[9];
int visited[9];

void dfs(int idx, int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = idx; i < N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            arr[cnt] = nums[i];
            dfs(i + 1, cnt + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> nums[i];
    sort(nums, nums + N);
    dfs(0, 0);
}