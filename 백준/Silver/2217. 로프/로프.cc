#include <algorithm>
#include <iostream>

using namespace std;

int capacities[100000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> capacities[i];
  sort(capacities, capacities + N, greater<>());

  int max_capacity = 0;
  
  for (int i = 0; i < N; i++) {
    if (max_capacity < (i + 1) * capacities[i]) max_capacity = (i + 1) * capacities[i];
  }
  cout << max_capacity;
}