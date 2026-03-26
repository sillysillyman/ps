#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N, n;
  long long s = 0;
  cin >> N;
  for (int i = 0; i < N * N; i++)
    cin >> n, s += n;
  cout << s;
}