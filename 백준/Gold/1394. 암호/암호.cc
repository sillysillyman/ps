#include <iostream>
#include <map>

using namespace std;

const int MOD = 900'528;
map<char, int> idxes;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int len, cnt = 0;
  string str, pwd;

  cin >> str >> pwd;
  len = str.length();
  for (int i = 0; i < len; i++) idxes[str[i]] = i;
  for (char& ch : pwd) cnt = (cnt * len + idxes[ch] + 1) % MOD;
  cout << cnt;
}