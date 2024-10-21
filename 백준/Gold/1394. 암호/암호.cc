#include <iostream>
#include <map>

using namespace std;

const int MOD = 900'528;
map<char, int> idx;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int len, cnt = 0;
  string str, pwd;

  cin >> str >> pwd;
  len = str.length();
  for (int i = 0; i < len; i++) idx[str[i]] = i;
  for (char& ch : pwd) cnt = (cnt * len + idx[ch] + 1) % MOD;
  cout << cnt;
}