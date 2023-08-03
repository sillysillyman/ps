#include <iostream>

using namespace std;

int main() {
  int N;
  int n;
  int cnt = 0;
  
  cin >> N;
  for (int i = 1; i <= N; i++) {
    string str_i = to_string(i);
    
    n = 0;
    for (char c : str_i) n += c - '0';
    if (i%n == 0) cnt++;
  }
  cout << cnt;
}