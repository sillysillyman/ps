#include <iostream>
#include <queue>

using namespace std;

int main() {
  int n, w, L;
  int time, res;
  queue<int> trucks;
  queue<int> bridge;

  cin >> n >> w >> L;

  for (int i = 0; i < n; i++) {
    int truck;

    cin >> truck;
    trucks.push(truck);
  }
  for (int i = 0; i < w; i++) bridge.push(0);

  int curr_load = 0;

  time = 0;
  while (!trucks.empty()) {
    // if (curr_load == 0 && trucks.empty()) break;
    if (trucks.front() + curr_load <= L) {
      curr_load -= bridge.front();
      bridge.pop();
      bridge.push(trucks.front());
      curr_load += trucks.front();
      trucks.pop();
    } else {
      curr_load -= bridge.front();
      bridge.pop();
      if (trucks.front() + curr_load <= L) {
        curr_load += trucks.front();
        bridge.push(trucks.front());
        trucks.pop();
      } else
        bridge.push(0);
    }
    time++;
  }
  res = time;
  time = 0;
  while (!bridge.empty()) {
    if (bridge.front()) {
      time++;
      bridge.pop();
      res += time;
      time = 0;
    } else {
      time++;
      bridge.pop();
    }
  }
  cout << res;
}