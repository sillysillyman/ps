#include <iostream>

using namespace std;

bool flag;
int N, S, T, W, w;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  while (N--) {
    cin >> S >> T;
    if (S > T) {
      w = flag ? w + 1 : 1;
      flag = 1;
    } else {
      w = 0;
      flag = 0;
    }
    if (w > W) W = w;
  }
  cout << W;
}