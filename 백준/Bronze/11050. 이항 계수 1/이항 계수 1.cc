#include <functional>
#include <iostream>

using namespace std;

int main() {
  int N, K;
  function<int(int)> factorial = [&factorial](int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
  };

  cin >> N >> K;
  cout << factorial(N) / factorial(K) / factorial(N - K);
}