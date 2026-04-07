#include <cstdio>
#include <numeric>

int main() {
  int A, B;
  scanf("%d%d", &A, &B);
  printf("%d", std::gcd(A, B));
}