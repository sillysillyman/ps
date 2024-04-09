#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;

  while (true) {
    float o, w;

    cin >> o >> w;
    if (o == 0 && w == 0) break;

    bool is_dead = false;

    while (true) {
      char cmd;
      int n;

      cin >> cmd >> n;
      if (cmd == '#') {
        cout << t;
        if (is_dead)
          cout << " RIP\n";
        else if (o / 2 < w && w < 2 * o)
          cout << " :-)\n";
        else
          cout << " :-(\n";
        break;
      } else if (cmd == 'E') {
        w -= n;
        if (w <= 0) is_dead = true;
      } else if (cmd == 'F')
        w += n;
    }
    t++;
  }
}