#include <iostream>
#include <map>
#include <queue>

using namespace std;

long long s, t;
queue<pair<long long, string>> q;
map<long long, bool> visited;

int main() {
  cin >> s >> t;
  if (s == t) {
    cout << 0;
    return 0;
  }
  q.push({s, ""});
  visited[s] = true;
  while (!q.empty()) {
    auto [num, operations] = q.front();

    q.pop();
    if (num == t) {
      cout << operations;
      return 0;
    } else if (num == 0)
      continue;
    if (num * num <= t && !visited[num * num]) {
      visited[num * num] = true;
      q.push({num * num, operations + "*"});
    }
    if (num + num <= t && !visited[num + num]) {
      visited[num + num] = true;
      q.push({num + num, operations + "+"});
    }
    if (!visited[num - num]) {
      visited[num - num] = true;
      q.push({num - num, operations + "-"});
    }
    if (!visited[num / num]) {
      visited[num / num] = true;
      q.push({num / num, operations + "/"});
    }
  }
  cout << -1;
}