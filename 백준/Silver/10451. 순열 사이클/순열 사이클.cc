#include <iostream>

using namespace std;

int cycles;
bool visited[1001];
int permutation[1001];

void dfs(int src_idx, int idx) {
  if (visited[idx]) return;
  visited[idx] = true;
  if (permutation[idx] == src_idx) {
    cycles++;
    return;
  }
  dfs(src_idx, permutation[idx]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T, N;

  cin >> T;
  while (T--) {
    cycles = 0;
    cin >> N;
    fill(visited + 1, visited + N + 1, false);
    for (int i = 1; i <= N; i++) cin >> permutation[i];
    for (int i = 1; i <= N; i++) dfs(i, i);
    cout << cycles << '\n';
  }
}