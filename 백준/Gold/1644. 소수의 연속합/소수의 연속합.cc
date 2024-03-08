#include <iostream>
#include <vector>

using namespace std;

bool sieve[4000001];
vector<int> primes;
vector<int> accumulated;

int main() {
  int N;
  int cnt = 0;

  fill(sieve + 2, sieve + 4000001, true);
  cin >> N;
  if (N == 1) {
    cout << 0;
    return 0;
  } else if (N == 2) {
    cout << 1;
    return 0;
  }
  for (int i = 2; i <= N; i++) {
    if (sieve[i]) {
      primes.push_back(i);
      for (int j = 2; i * j <= N; j++) sieve[i * j] = false;
    }
  }
  accumulated.push_back(0);
  for (int i = 0; i < primes.size(); i++)
    accumulated.push_back(accumulated[i] + primes[i]);
  
  int left = 0, right = 1;

  while (left < right && right < accumulated.size()) {
    int diff = accumulated[right] - accumulated[left];

    if (diff == N) {
      cnt++;
      if (right - left == 1) right++;
      left++;
    }
    else if (diff < N) right++;
    else if (diff > N) {
      if (right - left == 1) right++;
      left++;
    }
  }
  cout << cnt;
}