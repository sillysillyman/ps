#include <iostream>

using namespace std;

bool sieve[1001];

int main() {
  int N, K;

  cin >> N >> K;
  fill(sieve + 2, sieve + N + 1, true);
  for (int i = 2; i <= N; i++) {
    for (int j = 1; i * j <= N; j++) {
      if (sieve[i * j]) {
        sieve[i * j] = false;
        K--;
        if (K == 0) {
          cout << i * j;
          return 0;
        }
      }
    }
  }
}