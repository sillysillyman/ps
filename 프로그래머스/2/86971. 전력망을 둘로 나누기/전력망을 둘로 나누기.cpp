#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<bool> visited;
vector<vector<int>> graph;

int bfs(int src) {
  int size = 0;
  queue<int> queue;

  queue.push(src);
  visited[src] = true;
  ++size;
  while (!queue.empty()) {
    int curr = queue.front();

    queue.pop();
    for (int next : graph[curr]) {
      if (!visited[next]) {
        queue.push(next);
        visited[next] = true;
        ++size;
      }
    }
  }
  return size;
}

int solution(int n, vector<vector<int>> wires) {
  int answer = 100;

  visited.resize(n + 1);
  graph.resize(n + 1);
  for (auto wire : wires) {
    graph[wire[0]].push_back(wire[1]);
    graph[wire[1]].push_back(wire[0]);
  }
  for (auto wire : wires) {
    fill(visited.begin() + 1, visited.end(), false);
    graph[wire[0]].erase(
        remove(graph[wire[0]].begin(), graph[wire[0]].end(), wire[1]));
    graph[wire[1]].erase(
        remove(graph[wire[1]].begin(), graph[wire[1]].end(), wire[0]));
    answer = min(answer, abs(n - 2 * bfs(1)));
    graph[wire[0]].push_back(wire[1]);
    graph[wire[1]].push_back(wire[0]);
  }
  return answer;
}