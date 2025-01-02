#include <iostream>

using namespace std;

bool sieve[500'001];
int colors[500'001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  int color = 1;
  colors[1] = color;
  for (int i = 2; i <= N; i++) sieve[i] = true;
  for (int i = 2; i <= N; i++) {
    if (!sieve[i]) continue;
    colors[i] = ++color;
    for (int j = 2; i * j <= N; j++) {
      sieve[i * j] = false;
      colors[i * j] = color;
    }
  }
  cout << color << '\n';
  for (int i = 1; i <= N; i++) cout << colors[i] << ' ';
}