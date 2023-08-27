#include <iostream>
#include <vector>

using namespace std;

int N;
int parents[100001];
vector<int> tree[100001];

void dfs(int parent) {
    for (auto child : tree[parent]) {
        if (parents[parent] == child) continue;
        parents[child] = parent;
        dfs(child);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n1, n2;

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> n1 >> n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }
    dfs(1);
    for (int i = 2; i <= N; i++) cout << parents[i] << '\n';
}