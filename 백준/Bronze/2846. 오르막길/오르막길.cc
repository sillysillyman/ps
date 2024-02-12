#include <iostream>

using namespace std;

int sequence[1000];

int main() {
  int N;
  int max_uphill = 0;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> sequence[i];
  for (int i = 0; i < N; i++) {
    int uphill = 0;

    for (int j = i + 1; j < N; j++) {
      if (sequence[j] - sequence[j - 1] > 0) uphill = sequence[j] - sequence[i];
      else break;
    }
    max_uphill = max(max_uphill, uphill);
  }
  cout << max_uphill;
}