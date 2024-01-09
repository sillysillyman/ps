#include <iostream>

using namespace std;

int N, M;
int cnt = 500000;
int broken[10] = {};

void dfs(string channel) {
  for (int i = 0; i < 10; i++) {
    if (!broken[i]) {
      string new_channel = channel + to_string(i);

      cnt = min(cnt, abs(N - stoi(new_channel)) + (int)new_channel.length());
      if (new_channel.length() < 6) dfs(new_channel);
    }
  }
}

int main() {
  cin >> N >> M;
  cnt = min(cnt, abs(N - 100));
  if (M == 0) {
    cnt = min(cnt, (int)to_string(N).length());
    cout << cnt;
    return 0;
  }
  for (int i = 0; i < M; i++) {
    int button;

    cin >> button;
    broken[button] = 1;
  }
  dfs("");
  cout << cnt;
}