#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

ll solutions[5000];

int main() {
  int N;
  int arr[3];
  ll min_sum = 3e9;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> solutions[i];
  sort(solutions, solutions + N);
  for (int i = 0; i < N - 2; i++) {
    int low = i + 1;
    int high = N - 1;

    while (low < high) {
      int low_val = solutions[low];
      int high_val = solutions[high];
      ll sum = solutions[i];

      sum += solutions[low] + solutions[high];
      if (sum == 0) {
        cout << solutions[i] << ' ' << solutions[low] << ' ' << solutions[high];
        return 0;
      }
      if (sum > 0)
        high--;
      else
        low++;
      if (abs(min_sum) > abs(sum)) {
        min_sum = sum;
        arr[0] = solutions[i];
        arr[1] = low_val;
        arr[2] = high_val;
      }
    }
  }
  cout << arr[0] << ' ' << arr[1] << ' ' << arr[2];
}