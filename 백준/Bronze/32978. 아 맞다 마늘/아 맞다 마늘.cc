#include <iostream>
#include <set>

using namespace std;

int main() {
  int N;
  string s;
  set<string> S;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s;
    S.insert(s);
  }
  for (int i = 1; i < N; i++) {
    cin >> s;
    S.erase(s);
  }
  cout << *S.begin();
}