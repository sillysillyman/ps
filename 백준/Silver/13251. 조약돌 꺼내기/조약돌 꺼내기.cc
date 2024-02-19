#include <iostream>

using namespace std;

int pebbles[50];

int main() {
  int M, K, total = 0;
  double total_prob = 0;

  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> pebbles[i];
    total += pebbles[i];
  }
  cin >> K;
  for (int i = 0; i < M; i++) {
    long long numerator = pebbles[i];
    long long denominator = total;
    double ith_prob = 1;

    for (int j = 0; j < K; j++) {
      ith_prob *= ((double)numerator / denominator);
      numerator--;
      denominator--;
    }
    total_prob += ith_prob;
  }
  cout << fixed;
  cout.precision(10);
  cout << total_prob;
}