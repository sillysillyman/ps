#include <iostream>
#include <stack>

using namespace std;

stack<pair<int, int>> tops;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;

  cin >> N;
  for (int height, i = 1; i <= N; i++) {
    cin >> height;
    if (tops.empty()) {
      cout << 0 << ' ';
      tops.push({height, i});
    } else {
      if (tops.top().first >= height) {
        cout << tops.top().second << ' ';
        tops.push({height, i});
      } else {
        while (!tops.empty() && tops.top().first < height) tops.pop();
        if (tops.empty())
          cout << 0 << ' ';
        else
          cout << tops.top().second << ' ';
        tops.push({height, i});
      }
    }
  }
}