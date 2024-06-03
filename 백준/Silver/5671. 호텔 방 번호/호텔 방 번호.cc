#include <iostream>

using namespace std;

bool is_unique(int num) {
  bool visited[10];

  fill(visited, visited + 10, false);
  while (num) {
    if (visited[num % 10]) return false;
    visited[num % 10] = true;
    num /= 10;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;

  while (cin >> N >> M) {
    int cnt = 0;

    for (int i = N; i <= M; i++) {
      if (is_unique(i)) ++cnt;
    }
    cout << cnt << '\n';
  }
}