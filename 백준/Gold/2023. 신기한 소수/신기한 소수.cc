#include <iostream>

using namespace std;

int N;
int digits[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

bool is_prime(int num) {
  if (num <= 1) return false;
  if (num == 2) return true;
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) return false;
  }
  return true;
}

void dfs(int prime) {
  int num = prime;

  for (int i = 0; i < 10; i++) {
    prime = 10 * num + digits[i];
    if (!is_prime(prime)) continue;
    if (to_string(prime).length() == N) cout << prime << '\n';
    dfs(prime);
  }
}

int main() {
  cin >> N;
  dfs(0);
}