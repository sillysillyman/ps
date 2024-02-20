#include <iostream>
#include <vector>

using namespace std;

int N;
int cnts[501];
int visited[501];
int orders[501][501];

void dfs(int student, int direction) {
  if (visited[student]) return;
  visited[student] = true;
  for (int i = 1; i <= N; i++) {
    if (!visited[i] && orders[student][i] == direction) {
      cnts[i]++;
      dfs(i, direction);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int M;
  int cnt = 0;

  cin >> N >> M;
  for (int shorter, taller, i = 0; i < M; i++) {
    cin >> shorter >> taller;
    orders[shorter][taller] = 1;
    orders[taller][shorter] = -1;
  }
  for (int i = 1; i <= N; i++) {
    fill(visited + 1, visited + N + 1, false);
    dfs(i, 1);
    fill(visited + 1, visited + N + 1, false);
    dfs(i, -1);
  }
  for (int i = 1; i <= N; i++) {
    if (cnts[i] == N - 1) cnt++;
  }
  cout << cnt;
}