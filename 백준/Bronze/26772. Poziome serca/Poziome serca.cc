#include <iostream>

using namespace std;

string S[9] = {" @@@   @@@  ", "@   @ @   @ ", "@    @    @ ",
               "@         @ ", " @       @  ", "  @     @   ",
               "   @   @    ", "    @ @     ", "     @      "};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;
  for (auto &s : S) {
    for (int i = 0; i < N; i++)
      cout << s;
    cout << '\n';
  }
}