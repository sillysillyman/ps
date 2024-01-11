#include <iostream>
#include <vector>

using namespace std;

int sieve[4000001];
vector<int> primes;
vector<int> accumulated;

int main() {
  int N;
  int cnt = 0;

  fill(sieve + 2, sieve + 4000001, 1);
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
      for (int j = 2; i * j <= N; j++) sieve[i * j] = 0;
    }
  }
  for (int i = 2; i <= N; i++) {
    if (sieve[i]) primes.push_back(i);
  }
  for (int i = 0; i < primes.size(); i++) {
    if (i == 0) accumulated.push_back(primes[i]);
    else accumulated.push_back(accumulated[i - 1] + primes[i]);
  }
  
  int start = 0, end = 0;

//   for (auto i : primes) cout << i << ' ';
//   cout << "\n\n";
//   for (auto i : accumulated) cout << i << ' ';
//   cout << "\n\n";

  while (end < accumulated.size()) {
    // cout << "start: " << start << ", end: " << end << '\n';
    if (start == end) {
      if (accumulated[start] == N) cnt++;
      end++;
    }
    else {
      if (accumulated[end] - accumulated[start] == N) {
        cnt++;
        start++;
      }
      else if (accumulated[end] - accumulated[start] < N) end++;
      else if (accumulated[end] - accumulated[start] > N) {
        start++;
        end = start;
      }
    }
  }
  cout << cnt;
}