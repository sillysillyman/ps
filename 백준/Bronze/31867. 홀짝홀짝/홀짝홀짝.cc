#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, odd_cnt = 0, even_cnt = 0;
  string num;

  cin >> N;
  cin >> num;
  for (char& digit : num) {
    if ((digit - '0') & 1)
      ++odd_cnt;
    else
      ++even_cnt;
  }
  cout << (odd_cnt == even_cnt ? -1 : (odd_cnt < even_cnt ? 0 : 1));
}