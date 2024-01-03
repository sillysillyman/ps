#include <iostream>

using namespace std;

int main() {
  int N;
  long long sum = 0;

  cin >> N;
  for (int i = 1; i < N; i++) sum += (long long)N * i + i;
  cout << sum;
}