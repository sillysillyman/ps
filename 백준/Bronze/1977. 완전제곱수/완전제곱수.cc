#include <iostream>

using namespace std;

int main() {
  int M, N;
  int sum = 0;
  int min_square_number = -1;

  cin >> M >> N;
  for (int i = 1; i <= 10000; i++) {
    if (M <= i * i && i * i <= N) {
      if (min_square_number == -1) min_square_number = i * i;
      sum += i * i;
    }
    if (i * i > N) break;
  }
  if (sum == 0)
    cout << -1;
  else
    cout << sum << '\n' << min_square_number;
}