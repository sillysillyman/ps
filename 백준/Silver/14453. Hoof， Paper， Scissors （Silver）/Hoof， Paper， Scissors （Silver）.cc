#include <algorithm>
#include <iostream>

using namespace std;

int h, p, s;
char g[100'000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> g[i];
    if (g[i] == 'H')
      ++h;
    else if (g[i] == 'P')
      ++p;
    else
      ++s;
  }

  int max_win = max({h, p, s});
  int cur_h = 0, cur_p = 0, cur_s = 0;
  for (int i = 0; i < N; i++) {
    if (g[i] == 'H')
      ++cur_h;
    else if (g[i] == 'P')
      ++cur_p;
    else
      ++cur_s;

    max_win = max({max_win, cur_h + max(p - cur_p, s - cur_s),
                   cur_p + max(h - cur_h, s - cur_s),
                   cur_s + max(h - cur_h, p - cur_p)});
  }
  cout << max_win;
}