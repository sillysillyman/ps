#include <iostream>

using namespace std;

int main() {
  bool found = false;

  for (int i = 1; i <= 5; i++) {
    string agent;

    cin >> agent;
    if (agent.find("FBI") != string::npos) {
      cout << i << '\n';
      found = true;
    }
  }
  if (!found) cout << "HE GOT AWAY!";
}