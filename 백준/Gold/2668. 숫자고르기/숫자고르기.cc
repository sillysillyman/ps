#include <iostream>

using namespace std;

int cnt = 0;
bool found_cycle = false;
bool visited[101];
int arr[101];

void dfs(int i, int src, int size) {
  if (visited[i]) {
    if (i == src) {
      cnt += size;
      found_cycle = true;
      return;
    } else {
      found_cycle = false;
      return;
    }
  }
  visited[i] = true;
  size++;
  dfs(arr[i], src, size);
  if (!found_cycle) visited[i] = false;
}

int main() {
  int N;

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> arr[i];
  for (int i = 1; i <= N; i++) dfs(i, i, 0);
  cout << cnt << '\n';
  for (int i = 1; i <= N; i++) {
    if (visited[i]) cout << i << '\n';
  }
}