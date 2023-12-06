#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main() {
  int N;
  int cnt = 0;
  string car;
  queue<string> cars;
  map<string, int> passed;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> car;
    cars.push(car);
    passed[car]++;
  }
  for (int i = 0; i < N; i++) {
    cin >> car;
    while (passed[cars.front()] == 0) cars.pop();
    if (car == cars.front()) {
      cars.pop();
      passed[car]--;
    } else {
      cnt++;
      passed[car]--;
    }
  }
  cout << cnt;
}