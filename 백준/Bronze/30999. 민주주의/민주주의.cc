#include <iostream>

using namespace std;

int main() {
  int N, M;
  int cnt = 0;

  cin >> N >> M;
  while (N--) {
    char opinion;
    int pros = 0;

    for (int i = 0; i < M; i++) {
      cin >> opinion;
      if (opinion == 'O') pros++;
    }
    if (pros > M / 2) cnt++;
  }
  cout << cnt;
}