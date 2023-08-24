#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N, M;
int nums[9];
map<int, int> visited;
vector<int> v;

void dfs(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) cout << nums[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < N; i ++) {
        if (!visited[v[i]]) {
            visited[v[i]] = 1;
            nums[cnt] = v[i];
            dfs(cnt + 1);
            visited[v[i]] = 0;
        }
    }
}

int main() {
    int num;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    dfs(0);
}