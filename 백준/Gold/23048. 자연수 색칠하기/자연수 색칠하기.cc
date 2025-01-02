#include <iostream>

using namespace std;

int colors[500'001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  int color = 1;
  colors[1] = color;
  for (int i = 2; i <= N; i++) {
    if (colors[i]) continue;
    colors[i] = ++color;
    for (int j = 2; i * j <= N; j++) colors[i * j] = color;
  }
  cout << color << '\n';
  for (int i = 1; i <= N; i++) cout << colors[i] << ' ';
}