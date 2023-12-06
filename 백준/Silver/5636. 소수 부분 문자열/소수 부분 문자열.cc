#include <iostream>

using namespace std;

int sieve[100001] = {};

int main() {
  fill(sieve + 2, sieve + 100001, 1);
  for (int i = 2; i < 100001; i++) {
    if (sieve[i] == 0) continue;
    for (int j = 2; i * j < 100001; j++) sieve[i * j] = 0;
  }

  while (true) {
    string str;

    cin >> str;
    if (str == "0") break;

    int len = str.length();
    int max_num = 0;

    for (int i = 0; i < len; i++) {
      for (int j = 1; j <= min(6, len - i); j++) {
        int num = stoi(str.substr(i, j));

        if (num > 100000) continue;
        if (sieve[num]) max_num = max(max_num, num);
      }
    }
    cout << max_num << '\n';
  }
}