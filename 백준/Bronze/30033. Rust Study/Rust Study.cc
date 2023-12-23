#include <iostream>

using namespace std;

int main() {
  int N;

  cin >> N;

  int *planned = new int[N];
  int *studied = new int[N];

  for (int i = 0; i < N; i++) cin >> planned[i];
  for (int i = 0; i < N; i++) cin >> studied[i];

  int cnt = 0;

  for (int i = 0; i < N; i++) {
    if (planned[i] <= studied[i]) cnt++;
  }
  cout << cnt;
  delete[] planned;
  delete[] studied;
}