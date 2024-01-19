#include <iostream>
#include <stack>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, K;
  string num;
  string ans;
  stack<char> s;

  cin >> N >> K;
  cin >> num;
  for (int i = 0; i < N; i++) {
    if (K == 0) {
      ans = num.substr(i);
      break;
    }
    while (K != 0 && !s.empty() && num[i] > s.top()) {
      s.pop();
      K--;
    }
    s.push(num[i]);
    // tmp += digit;
    // cout << "tmp: " << tmp << endl;
  }
  while (K != 0) {
    s.pop();
    K--;
  }
  while (!s.empty()) {
    ans = s.top() + ans;
    s.pop();
  }
  cout << ans;
}