#include <iostream>

using namespace std;

int main() {
  bool has_y = false;
  int vowels_cnt = 0;
  int y_cnt = 0;
  string word;

  cin >> word;
  for (char letter : word) {
    if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' ||
        letter == 'u')
      vowels_cnt++;
    else if (letter == 'y')
      y_cnt++;
  }
  cout << vowels_cnt << " " << vowels_cnt + y_cnt;
}