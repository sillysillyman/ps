#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int N, M, K;
  int cnt = 0;

  cin >> N >> M >> K;
  cout << ceil((double)N / (K - M));
}