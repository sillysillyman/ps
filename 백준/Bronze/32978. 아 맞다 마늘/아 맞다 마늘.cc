#include <iostream>
#include <set>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;
  string s;
  set<string> S;
  cin >> N;
  for (int i = 0; i < 2 * N - 1; i++) {
    cin >> s;
    if (i < N) S.insert(s);
    else S.erase(s);
  }
  cout << *S.begin();
}