#include <iostream>
#include <map>
#include <queue>

using namespace std;

const int MOD = 1000000000;
map<int, int> visited;

int bfs(int a, int b) {
  queue<pair<int, int>> q;

  q.push({a, 1});
  visited[a] = 1;
  while (!q.empty()) {
    auto [n, cnt] = q.front();

    q.pop();
    if (n == b)
      return cnt;
    else if (n > b)
      break;
    if (long long m = (long long)n * 2; m <= b && !visited[m]) {
      q.push({m, cnt + 1});
      visited[m] = 1;
    }
    if (long long m = (long long)n * 10 + 1; m <= b && !visited[m]) {
      q.push({m, cnt + 1});
      visited[m] = 1;
    }
  }
  return -1;
}

int main() {
  int A, B;

  cin >> A >> B;
  cout << bfs(A, B);
}