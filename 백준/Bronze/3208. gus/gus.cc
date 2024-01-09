#include <iostream>

using namespace std;

int main() {
  int M, N;

  cin >> M >> N;
  cout << min(2 * M - 2, 2 * N - 1);
}