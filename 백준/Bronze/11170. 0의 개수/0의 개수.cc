#include <iostream>

using namespace std;

int main() {
  int T;
  int cnt;

  cin >> T;
  while (T--) {
    int N, M;

    cin >> N >> M;
    cnt = 0;
    for (int i = N; i <= M; i++) {
      string num = to_string(i);

      for (char digit : num) {
        if (digit == '0') cnt++;
      }
    }
    cout << cnt << '\n';
  }
}