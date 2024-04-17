#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, sum = 0;

  cin >> N;
  for (int num, i = 0; i < N; i++) {
    cin >> num;
    sum += num - 1;
  }
  sum++;
  cout << sum;
}