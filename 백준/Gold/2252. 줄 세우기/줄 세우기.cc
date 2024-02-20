#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool visited[32'001];
int indegrees[32'001];
vector<int> orders[32'001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  queue<int> q;

  cin >> N >> M;
  for (int A, B, i = 0; i < M; i++) {
    cin >> A >> B;
    indegrees[B]++;
    orders[A].push_back(B);
  }
  for (int i = 1; i <= N; i++) {
    if (indegrees[i] == 0) {
      visited[i] = true;
      q.push(i);
    }
  }
  while (!q.empty()) {
    int taller = q.front();

    cout << taller << ' ';
    q.pop();
    for (int shorter : orders[taller]) {
      indegrees[shorter]--;
      if (!visited[shorter] && indegrees[shorter] == 0) {
        visited[shorter] = true;
        q.push(shorter);
      }
    }
  }
}