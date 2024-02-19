#include <algorithm>
#include <iostream>

using namespace std;

int N, M;
int arr[8];
int num[8];
bool visited[8];

void dfs(int idx, int depth) {
  if (depth == M) {
    for (int i = 0; i < M; i++) cout << num[i] << ' ';
    cout << '\n';
    return;
  }

  int prev = 0;

  for (int i = idx; i < N; i++) {
    if (!visited[i] && prev != arr[i]) {
      visited[i] = true;
      num[depth] = arr[i];
      prev = arr[i];
      dfs(i, depth + 1);
      visited[i] = false;
    }
  }
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> arr[i];
  sort(arr, arr + N);
  dfs(0, 0);
}