#include <cstdio>
#include <vector>

using namespace std;

vector<int> primes;

bool is_prime(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}

bool is_possible(int n) {
  for (int i = 0; i < primes.size(); i++)
    for (int j = i; j < primes.size(); j++)
      if (primes[i] + primes[j] == n) return true;
  return false;
}

int main() {
  for (int i = 1; i <= 118; i++)
    if (is_prime(i)) primes.push_back(i);

  int N;
  scanf("%d", &N);
  while (N--) {
    int a;
    scanf("%d", &a);
    printf("%s\n", is_possible(a) ? "Yes" : "No");
  }
}