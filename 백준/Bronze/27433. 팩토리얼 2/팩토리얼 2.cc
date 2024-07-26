#include <cstdio>
#include <functional>

using namespace std;

int main() {
  int N;
  function<long long(int)> factorial = [&factorial](int n) -> long long {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
  };

  scanf("%d", &N);
  printf("%lld", factorial(N));
}