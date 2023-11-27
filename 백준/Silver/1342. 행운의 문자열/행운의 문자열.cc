#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int len;
  int cnt = 0;
  string S;

  cin >> S;
  len = S.length();
  sort(S.begin(), S.end());
  do {
    bool is_unlucky = false;

    for (int i = 0; i < len - 1; i++) {
      if (S[i] == S[i + 1]) {
        is_unlucky = true;
        break;
      }
    }
    if (is_unlucky) continue;
    cnt++;
  } while (next_permutation(S.begin(), S.end()));
  cout << cnt;
}