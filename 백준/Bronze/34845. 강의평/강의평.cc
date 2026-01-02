#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, X, A = 0;
  cin >> N >> X;
  for (int a, i = 0; i < N; i++) {
    cin >> a;
    A += a;
  }
  printf("%d", N * X - A <= 0 ? 0 : (N * X - A) / (100 - X) + !!((N * X - A) % (100 - X)));
}