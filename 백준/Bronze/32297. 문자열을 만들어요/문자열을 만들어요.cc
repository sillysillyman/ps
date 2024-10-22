#include <iostream>

using namespace std;

int main() {
  int N;
  string str;

  cin >> N >> str;
  cout << (str.find("gori") != string::npos ? "YES" : "NO");
}