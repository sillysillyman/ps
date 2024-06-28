#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string target, guess;

  while (true) {
    cin >> target;
    if (target == "#") break;
    cin >> guess;

    int len = target.length();
    int b = 0, g = 0, w = 0;
    vector<bool> target_checked(len, false);
    vector<bool> guess_checked(len, false);

    for (int i = 0; i < len; ++i) {
      if (guess[i] == target[i]) {
        b++;
        target_checked[i] = true;
        guess_checked[i] = true;
      }
    }
    for (int i = 0; i < len; ++i) {
      if (guess_checked[i]) continue;
      if (i > 0 && guess[i] == target[i - 1] && !target_checked[i - 1]) {
        g++;
        target_checked[i - 1] = true;
        guess_checked[i] = true;
      } else if (i < len - 1 && guess[i] == target[i + 1] &&
                 !target_checked[i + 1]) {
        g++;
        target_checked[i + 1] = true;
        guess_checked[i] = true;
      }
    }
    for (int i = 0; i < len; ++i) {
      if (guess_checked[i]) continue;
      for (int j = 0; j < len; ++j) {
        if (target_checked[j]) continue;
        if (guess[i] == target[j]) {
          w++;
          target_checked[j] = true;
          break;
        }
      }
    }
    cout << guess << ": " << b << " black, " << g << " grey, " << w
         << " white\n";
  }
}