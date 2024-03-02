#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;

  cin >> T;
  while (T--) {
    int N, M;

    cin >> N >> M;
    for (int src, dest, i = 0; i < M; i++) cin >> src >> dest;
    cout << N - 1 << '\n';
  }
}