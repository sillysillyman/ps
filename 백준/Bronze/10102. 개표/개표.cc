#include <iostream>

using namespace std;

int main() {
  int V, A = 0, B = 0;

  cin >> V;
  for (int i = 0; i < V; i++) {
    char vote;

    cin >> vote;
    if (vote == 'A')
      A++;
    else if (vote == 'B')
      B++;
  }
  cout << (A == B ? "Tie" : (A > B ? "A" : "B"));
}