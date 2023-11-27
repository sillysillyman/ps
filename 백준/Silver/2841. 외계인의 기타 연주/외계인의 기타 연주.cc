#include <iostream>
#include <stack>

using namespace std;

stack<int> guitar[6];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, P;
  int finger_move = 0;

  cin >> N >> P;
  for (int i = 0; i < N; i++) {
    int string, fret;

    cin >> string >> fret;
    string--;
    if (guitar[string].empty() || guitar[string].top() < fret) {
      guitar[string].push(fret);
      finger_move++;
    } else {
      while (guitar[string].top() > fret) {
        guitar[string].pop();
        finger_move++;
        if (guitar[string].empty()) break;
      }
      if (!guitar[string].empty() && guitar[string].top() == fret) continue;
      guitar[string].push(fret);
      finger_move++;
    }
  }
  cout << finger_move;
}