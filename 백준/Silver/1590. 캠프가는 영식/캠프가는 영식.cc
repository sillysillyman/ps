#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, T;
  int min_wait_time = 1000000;
  int valid_buses = 0;

  cin >> N >> T;
  for (int i = 0; i < N; i++) {
    int S, I, C;

    cin >> S >> I >> C;
    if (S + I * (C - 1) < T) continue;
    if (S == T) min_wait_time = 0;
    else if (S > T) min_wait_time = min(min_wait_time, S - T);
    else {
      int arrival_time = S;

      while (arrival_time < T) arrival_time += I;
      min_wait_time = min(min_wait_time, arrival_time - T);
    }
    valid_buses++;
  }
  if (!valid_buses) cout << -1;
  else cout << min_wait_time;
}