#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
int cnt;
int max_cnt = 0;
bool visited[10001];
vector<int> topology[10001];
vector<pair<int, int>> hackables;

void dfs(int n) {
  if (visited[n]) return;
  cnt++;
  visited[n] = true;
  for (auto computer : topology[n]) {
    if (!visited[computer]) dfs(computer);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  for (int A, B, i = 0; i < M; i++) {
    cin >> A >> B;
    topology[B].push_back(A);
  }
  for (int i = 1; i <= N; i++) {
    cnt = 0;
    fill(visited + 1, visited + N + 1, false);
    dfs(i);
    max_cnt = max(max_cnt, cnt);
    hackables.push_back({i, cnt});
  }
  sort(hackables.begin(), hackables.end(), [](auto a, auto b) {
    if (a.second == b.second)
      return a.first < b.first;
    else
      return a.second > b.second;
  });
  for (auto hackable : hackables) {
    if (hackable.second != max_cnt) break;
    cout << hackable.first << ' ';
  }
}