#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, K;
  string num;
  string ans;

  cin >> N >> K;
  cin >> num;
  for (int i = 0; i < N; i++) {
    if (K == 0) {
      ans += num.substr(i);
      break;
    }
    while (K != 0 && !ans.empty() && num[i] > ans.back()) {
      ans.pop_back();
      K--;
    }
    ans.push_back(num[i]);
  }
  while (K != 0) {
    ans.pop_back();
    K--;
  }
  cout << ans;
}