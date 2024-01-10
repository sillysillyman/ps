#include <iostream>
#include <queue>

using namespace std;

int N, K;
int times[100001];

bool is_inside(int idx) { return 0 <= idx && idx < 100001; }

void bfs(int src) {
  queue<int> q;

  q.push(src);
  while (!q.empty()) {
    int cur = q.front();

    if (cur == K) {
      cout << times[cur];
      return;
    }
    q.pop();
    if (is_inside(cur - 1) && times[cur] + 1 <= times[cur - 1]) {
      times[cur - 1] = times[cur] + 1;
      q.push(cur - 1);
    }
    if (is_inside(cur + 1) && times[cur] + 1 <= times[cur + 1]) {
      times[cur + 1] = times[cur] + 1;
      q.push(cur + 1);
    }
    if (is_inside(2 * cur) && times[cur] <= times[2 * cur]) {
      times[2 * cur] = times[cur];
      q.push(2 * cur);
    }
  }
}

int main() {
  cin >> N >> K;
  fill(times, times + 100001, 100000);
  times[N] = 0;
  bfs(N);
}