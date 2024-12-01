#include <algorithm>
#include <cstdio>
#include <tuple>

using namespace std;

int h, p, s;
char g[100'000];

int main() {
  int N;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf(" %c", &g[i]);
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
  printf("%d", max_win);
}