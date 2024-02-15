#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int K, N;
  vector<int> primes;
  priority_queue<int, vector<int>, greater<>> pq;

  cin >> K >> N;
  for (int prime, i = 0; i < K; ++i) {
    cin >> prime;
    primes.push_back(prime);
  }
  pq.push(1);
  while (N--) {
    int num = pq.top();

    for (int prime : primes) {
      if ((long long)num * prime <= ~(1 << 31))
        pq.push(num * prime);
    }
    pq.pop();
    while (pq.top() == num) pq.pop();
  }
  cout << pq.top();
}