#include <iostream>
#include <vector>

using namespace std;

int N, K = 0;
vector<pair<int, int>> process;

string add(string a, string b) {
  if (a.length() < b.length()) swap(a, b);
  
  int len = a.length();
  int len_diff = len - b.length();

  for (int i = 0; i < len_diff; i++) b = "0" + b;

  int carry = 0;
  string ret = "";

  for (int i = len - 1; i >= 0; i--) {
    int num = (a[i] - '0') + (b[i] - '0') + carry;
    
    carry = num/10;
    num %= 10;
    ret = to_string(num) + ret;
  }
  if (carry) ret = "1" + ret;
  return ret;
}

string pow_of_two(string a, int n) {
  if (n == 0) return "1";
  else if (n == 1) return a;
  for (int i = 1; i < n; i++) a = add(a, a);
  return a;
}

void hanoi(int n, int from, int via, int to) {
  if (n == 0) return;
  hanoi(n - 1, from, to, via);
  K++;
  if (N <= 20) process.push_back({from, to});
  hanoi(n - 1, via, from, to);
}

int main() {
  cin >> N;
  if (N <= 20) {
    hanoi(N, 1, 2, 3);
    cout << K << '\n';
    for (auto p : process) cout << p.first << " " << p.second << '\n';
  } else {
    string res = pow_of_two("2", N);
    int len = res.length();
    
    for (int i = len - 1; i >= 0; i--) {
      if (res[i] - '0' > 0) {
        res[i] -= 1;
        break;
      } else  res[i] = '9'; 
    }
    cout << res;
  }
}