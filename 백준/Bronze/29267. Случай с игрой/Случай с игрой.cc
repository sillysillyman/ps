#include <iostream>

using namespace std;

int main() {
  int n, k;
  int curr_bullet = 0, saved_bullet = 0;

  cin >> n >> k;
  while (n--) {
    string cmd;

    cin >> cmd;
    if (cmd == "save")
      saved_bullet = curr_bullet;
    else if (cmd == "load")
      curr_bullet = saved_bullet;
    else if (cmd == "shoot")
      --curr_bullet;
    else if (cmd == "ammo")
      curr_bullet += k;
    cout << curr_bullet << '\n';
  }
}