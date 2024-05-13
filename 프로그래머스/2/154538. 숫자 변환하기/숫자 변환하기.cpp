#include <map>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {
  map<int, bool> visited;
  queue<pair<int, int>> queue;

  queue.push({x, 0});
  visited[x] = true;
  while (!queue.empty()) {
    auto [x, cnt] = queue.front();

    if (x == y) return cnt;
    queue.pop();
    if (!visited[x + n] && x + n <= y) {
      queue.push({x + n, cnt + 1});
      visited[x + n] = true;
    }
    if (!visited[2 * x] && 2 * x <= y) {
      queue.push({2 * x, cnt + 1});
      visited[2 * x] = true;
    }
    if (!visited[3 * x] && 3 * x <= y) {
      queue.push({3 * x, cnt + 1});
      visited[3 * x] = true;
    }
  }
  return -1;
}