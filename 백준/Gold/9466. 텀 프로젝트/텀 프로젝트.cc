#include <iostream>

using namespace std;

int cnt = 0;
const int MAX_N = 100'000;
bool visited[MAX_N + 1];
bool finished[MAX_N + 1];
int arr[MAX_N + 1];

void dfs(int curr) {
  visited[curr] = true;

  int next = arr[curr];

  if (!visited[next])
    dfs(next);
  else if (!finished[next]) {
    for (int i = next; i != curr; i = arr[i]) cnt++;
    cnt++;
  }
  finished[curr] = true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;

  cin >> T;
  while (T--) {
    int n;

    cin >> n;
    cnt = 0;
    fill(visited + 1, visited + n + 1, false);
    fill(finished + 1, finished + n + 1, false);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
      if (!visited[i]) dfs(i);
    }
    cout << n - cnt << '\n';
  }
}