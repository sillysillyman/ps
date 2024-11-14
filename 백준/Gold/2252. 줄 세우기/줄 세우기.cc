#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int indeg[32'001];
vector<int> orders[32'001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  queue<int> q;

  cin >> N >> M;
  for (int A, B, i = 0; i < M; i++) {
    cin >> A >> B;
    ++indeg[B];
    orders[A].push_back(B);
  }
  for (int i = 1; i <= N; i++)
    if (!indeg[i]) q.push(i);
  for (int i = 1; i <= N; i++) {
    int taller = q.front();

    cout << taller << ' ';
    q.pop();
    for (int shorter : orders[taller])
      if (!--indeg[shorter]) q.push(shorter);
  }
}