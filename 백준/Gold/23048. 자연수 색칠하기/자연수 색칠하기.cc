#include <iostream>

using namespace std;

unsigned short colors[500'001];

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
    for (int j = i; j <= N; j += i) colors[j] = color;
  }

  string output = "";
  for (int i = 1; i <= N; i++) output += to_string(colors[i]) + ' ';
  cout << color << '\n' << output;
}